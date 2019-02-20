
#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>

#include "oa_sort.h"


namespace otusalg
{


template<typename T>
T nth_el(const std::vector<T> &v)
{
	std::vector<T> cv (v.begin(), v.end());
	std::vector<T> medians;
	std::size_t medcnt = cv.size() / 5 * 5;
	for(auto i=cv.begin(); i<cv.begin()+medcnt; i += 5)
	{
		ins_sort(i, i+5, std::less<int>());
		medians.push_back(*(i+2));
	}
	// ins_sort(cv[medcnt], cv[cv.size() - 1], std::less<int>());
	// medians.push_back(cv[(cv.size() - medcnt - 1) / 2 + medcnt]);

	std::cout << "Medians:\n";
	std::copy(medians.begin(), medians.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}



} // namespace otusalg

