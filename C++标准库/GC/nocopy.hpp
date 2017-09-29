#ifndef NOCOPY_HPP
#define NOCOPY_HPP

namespace Recycling {

	class nocopy
	{
	public:
		nocopy() {}
		nocopy(const nocopy&) = delete;
		nocopy(const nocopy&&) = delete;
		nocopy &operator = (const nocopy&) = delete;
		nocopy &operator = (const nocopy&&) = delete;
	};
}

#endif