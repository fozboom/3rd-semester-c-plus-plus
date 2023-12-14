#ifndef UNTITLED_ALGORITHM_H
#define UNTITLED_ALGORITHM_H

class Algorithm
{
public:
    template <typename Iterator, typename Compare, typename Tree>
    static void searchByFiltration (Iterator start, Iterator stop,Tree& newTree,Compare comp)
    {
        for(Iterator it = start; it != stop; ++it)
        {
            if(comp(*it))
            {
                newTree.push(*it);
            }
        }
    }
    template <typename Iterator>
    static int totalCount(Iterator begin, Iterator end)
    {
        int count = 0;
        for (auto it = begin; it != end; ++it)
        {
            ++count;
        }
        return count;
    }

    template <typename Iterator, typename T>
    static Iterator find(Iterator begin, Iterator end, const T& value)
    {
        for (auto it = begin; it != end; ++it)
        {
            if (*it == value) {
                return it;
            }
        }
        return end;
    }

    template <typename Iterator, typename T>
    static Iterator binarySearch(Iterator begin, Iterator end, const T& value)
    {
        Iterator lowerBound = std::lower_bound(begin, end, value);
        if(lowerBound != end && *lowerBound == value)
        {
            return lowerBound;
        }
        return end;
    }
    template <typename Iterator>
    static Iterator maxElement(Iterator begin, Iterator end)
    {
        return std::max_element(begin, end);
    }
};

#endif //UNTITLED_ALGORITHM_H
