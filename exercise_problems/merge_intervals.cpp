#include <iostream>
#include <vector>

class Interval
{
private:
	int start;
	int end; 
public:
	Interval(int start, int end) : start(start), end(end) {};
	int get_start() { return start; }
	int get_end() { return end; }
	friend std::ostream& operator<<(std::ostream &out, const Interval &i)
	{
		out << "[" << i.start << "," << i.end << "]";
		return out; 
	}
};

std::vector<Interval> merge_intervals(std::vector<Interval> intervals)
{
	std::vector<Interval> result;
	Interval prev = intervals[0];
	for(int i = 1; i < intervals.size(); ++i)
	{
		if(intervals[i].get_start() <= prev.get_end())
		{
			int max_end = (intervals[i].get_end() > prev.get_end()) ? intervals[i].get_end() : prev.get_end();
			Interval merged_interval(prev.get_start(), max_end);
			prev = merged_interval;
		}
		else
		{
			result.push_back(prev);
			prev = intervals[i];
		}
	}
	result.push_back(prev);
	return result;
}

int main(int argc, char const *argv[])
{
	std::vector<Interval> intervals;
	Interval i1(1,5), i2(3,7), i3(30, 45), i4(35, 55);
	intervals.push_back(i1);
	intervals.push_back(i2);
	intervals.push_back(i3);
	intervals.push_back(i4);

	std::vector<Interval> result = merge_intervals(intervals);
	for(int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}