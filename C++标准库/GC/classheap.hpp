#ifndef RECYCLING_CLASS_HEAP_HPP
#define RECYCLING_CLASS_HEAP_HPP

#include <cstdlib>
#include <cstdint>
#include <typeinfo>
#include <unordered_map>
#include "nocopy.hpp"

namespace Recycling {
	namespace gc {
		struct gc_object
		{
			const static uint8_t white = 0;
			const static uint8_t gray = 1;
			const static uint8_t black = 2;

			int counter;

			uint8_t marked;

			char buff[1];
		};

		template<typename Class>
		inline gc_object* gc_object_cast(Class *obj) {
			return reinterpret_cast<gc_object*>((uint8_t*)obj - offsetof(gc_object, buff));
		}

		template<typename Class>
		inline void make_destory(void * buff, std::size_t) {
			((Class*) buff)->~Class();

			buff = nullptr;
		}

		class classheap : private nocopy {
		public:
			using destory = void(*)(void * buff, std::size_t nsize)
		public:
			classheap(std::size_t size, destory f) : _size(size), destory(f), _idgen(1) {

			}

			~classheap() {
				for (auto iter : _shared) {
					if (iter.second->marked == gc_object::gray) {
						_destroy(iter.second->buff, _size);
					}

					free(iter.second);
				}

				for (auto iter : _weak) {
					if (iter.second->marked == gc_object::gray) {
						_destroy(iter.second->buff, _size);
					}

					free(iter.second);
				}
			}

			gc_object *alloc(uint32_t & id) {
				for (; ;) {
					if (_shared[_idgen] == nullptr && _weak[_idgen] == nullptr) {
						id = _idgen++;

						if (id == 0)
							id = _idgen++;

						std::size_t nsize = _size + sizeof(gc_object);

						gc_object * obj = (gc_object*)malloc(nsize);

						memset(obj, 0, nsize);

						obj->marked = gc_object::white;
						obj->counter = 1;
						_shared[id] = obj;

						return obj;
					}
				}

			}

			gc_object *lock(uint32_t id) {
				auto iter = _shared.find(id);

				if (iter ==_shared.end()) {
					iter = _weak.find(id);

					if (iter == _weak.end()) {
						return nullptr;
					}

					if (iter->second->marked != gc_object::white) {
						return nullptr;
					}

					_shared.insert(*iter);

					auto gcobj = iter->second;

					gcobj->counter++;

					_weak.erase(iter);

					return gcobj;
				}
				else {
					if (iter->second->marked == gc_object::white) {
						auto gcobj = iter->second;

						gcobj->counter++;

						return gcobj;
					}
				}

				return nullptr;
			}

			void unlock(gc_object *obj, uint32_t id) {
				if (--obj->counter == 0) {
					_shared.erase(id);
					_weak[id] = obj;
				}
			}

			void collect() {
				for (auto kv : _weak) {
					if (kv.second->marked != gc_object::black) {
						_destroy(kv.second->buff, _size);
					}

					free(kv.second);
				}

				_weak.clear();
			}

		private:
			std::size_t _size;
			destory _destroy;
			uint32_t _idgen;
			std::unordered_map<uint32_t, gc_object*>_shared;
			std::unordered_map<uint32_t, gc_object*>_weak;
		};
	}
}

#endif