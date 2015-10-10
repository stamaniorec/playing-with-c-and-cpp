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

void add_interval(std::vector<Interval> &intervals, int new_interval_start, int new_interval_end)
{
	Interval new_interval(new_interval_start, new_interval_end);
	std::vector<Interval> result;
	for(int i = 0; i < intervals.size(); ++i)
	{
		if(intervals[i].get_start() > new_interval.get_end())
		{
			result.push_back(new_interval);
			new_interval = intervals[i];
		}
		else if(intervals[i].get_end() < new_interval.get_start())
		{
			result.push_back(intervals[i]);
		}
		else
		{
			int merged_start = (new_interval_start < intervals[i].get_start()) ? new_interval_start : intervals[i].get_start();
			int merged_end = (new_interval_end > intervals[i].get_end()) ? new_interval_end : intervals[i].get_end();
			Interval merged_interval(merged_start, merged_end);
			new_interval = merged_interval;
		}
	}
	result.push_back(new_interval);
	intervals = result;
}

int main(int argc, char const *argv[])
{
	std::vector<Interval> intervals;
	Interval i1(1,5);
	Interval i2(7,14);
	intervals.push_back(i1);
	intervals.push_back(i2);
	for(int i = 0; i < intervals.size(); ++i)
	{
		std::cout << intervals[i] << " ";
	}
	std::cout << std::endl;

	add_interval(intervals, 0, 10);

	for(int i = 0; i < intervals.size(); ++i)
	{
		std::cout << intervals[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}