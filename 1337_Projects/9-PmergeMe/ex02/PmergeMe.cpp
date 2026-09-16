#include "PmergeMe.hpp"

/*Vector implementation*/

std::vector<std::size_t> JacobsthalSeqMakerVect(std::size_t size)
{
    std::vector<std::size_t> sequence;
    
    if (size == 0)
        return sequence;
    
    sequence.push_back(1);
    
    std::size_t previous = 1;
    std::size_t current = 3;
    
    while (previous < size)
    {
        std::size_t end = current;
        
        if (end > size)
            end = size;
        
        std::size_t i = end;
        
        while (i > previous)
        {
            sequence.push_back(i);
            --i;
        }
        
        std::size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return sequence;
}

bool LowerBoundVect(const VectFord &item1, const VectFord &item2)
{
    return item1.value < item2.value;
}

void FordJohnsonVector(Vect& vec)
{
	if (vec.size() <= 1)
		return;
	
	bool carry = vec.size() % 2 != 0;

	VectFord carryHolder = 0;
	if (carry)
	{
		carryHolder = vec.back();
		vec.pop_back();
	}

	for (Vect::iterator it = vec.begin(); it != vec.end() && (it + 1) != vec.end();)
	{
		if (it->value < (it + 1)->value)
			std::swap(*it, *(it + 1));
		it->losers.push_back(*(it + 1));
		it = vec.erase(it + 1);
	}
	std::size_t LosersCount = vec[0].losers.size();

	FordJohnsonVector(vec);
	
	std::vector<size_t> JacobsthalSeq =  JacobsthalSeqMakerVect(vec.size());
	
	for (std::size_t j = 0; j < JacobsthalSeq.size(); j++)
    {
        std::size_t target = JacobsthalSeq[j] - 1;
        for (std::size_t i = 0; i < vec.size(); i++)
        {
            if (vec[i].losers.size() != LosersCount)
                continue;
            if (target == 0)
            {
                VectFord guest = vec[i].losers.back();
                Vect::iterator place = std::lower_bound(vec.begin(), vec.begin() + i, guest, LowerBoundVect);
                vec.insert(place, guest);
                break;
            }
            target--;
        }
    }
	for (std::size_t i = 0; i < vec.size(); i++) 
    {
        if (vec[i].losers.size() == LosersCount)
            vec[i].losers.pop_back();
    }
    if (carry)
    {
		Vect::iterator place = std::lower_bound(vec.begin(), vec.end(), carryHolder, LowerBoundVect);
        vec.insert(place, carryHolder);
    }
}


/*Deque implementation*/

std::deque<std::size_t> JacobsthalSeqMakerDeq(std::size_t size)
{
    std::deque<std::size_t> sequence;
    
    if (size == 0)
        return sequence;
    
    sequence.push_back(1);
    
    std::size_t previous = 1;
    std::size_t current = 3;
    
    while (previous < size)
    {
        std::size_t end = current;
        
        if (end > size)
            end = size;
        
        std::size_t i = end;
        
        while (i > previous)
        {
            sequence.push_back(i);
            --i;
        }
        
        std::size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return sequence;
}

bool LowerBoundDeq(const DeqFord &item1, const DeqFord &item2)
{
    return item1.value < item2.value;
}

void FordJohnsonDeque(Deq& deq)
{
	if (deq.size() <= 1)
		return;
	
	bool carry = deq.size() % 2 != 0;

	DeqFord carryHolder = 0;
	if (carry)
	{
		carryHolder = deq.back();
		deq.pop_back();
	}

	for (Deq::iterator it = deq.begin(); it != deq.end() && (it + 1) != deq.end();)
	{
		if (it->value < (it + 1)->value)
			std::swap(*it, *(it + 1));
		it->losers.push_back(*(it + 1));
		it = deq.erase(it + 1);
	}
	std::size_t LosersCount = deq[0].losers.size();

	FordJohnsonDeque(deq);
	
	std::deque<size_t> JacobsthalSeq =  JacobsthalSeqMakerDeq(deq.size());
	
	for (std::size_t j = 0; j < JacobsthalSeq.size(); j++)
    {
        std::size_t target = JacobsthalSeq[j] - 1;
        for (std::size_t i = 0; i < deq.size(); i++)
        {
            if (deq[i].losers.size() != LosersCount)
                continue;
            if (target == 0)
            {
                DeqFord guest = deq[i].losers.back();
                Deq::iterator place = std::lower_bound(deq.begin(), deq.begin() + i, guest, LowerBoundDeq);
                deq.insert(place, guest);
                break;
            }
            target--;
        }
    }
	for (std::size_t i = 0; i < deq.size(); i++) 
    {
        if (deq[i].losers.size() == LosersCount)
            deq[i].losers.pop_back();
    }
    if (carry)
    {
		Deq::iterator place = std::lower_bound(deq.begin(), deq.end(), carryHolder, LowerBoundDeq);
        deq.insert(place, carryHolder);
    }
}
