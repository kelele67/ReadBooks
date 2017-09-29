#include "threadheap.hpp"

namespace Recycling {
	namespace gc {
		thread_local threadheap _threadheap;

		threadheap & get_threadheap() {
			return _threadheap;
		}
	}
}