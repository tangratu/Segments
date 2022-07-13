

#include <iostream>
#include <vector>
class Segment {
	int start;
	int end;
public:
	Segment() : start(0), end(0) {

	}
	Segment(int s, int e)   {
		if (s < e) { start = s; end = e; }
		else {
			start = e;
			end = s;
		}
	}
	int getoverlap(int st, int en) {
		int s, e;
		if (st < en) { s = st; e = en; }
		else { s = en; e = st; }
		if (start < s) { 
			if (end > s) return end - s;
			return 0;
		}
		if (start > s) {
			if (e > start) return e - start;
			return 0;
		}
		return 0;
	}
};
int main()
{
    int n, a, b, c;
	
    std::cin >> n >> a >> b >> c;
	int unp = n;	
	std::vector<Segment> pairs;
	int count = 0;
	for (int i = 0; i < n; i+=a)
	{
		for (int z = n; z > 0; z-=b)
		{
			if (z - i == c || i - z == c) {

				unp  -= c;
				for (size_t y = 0; y < count; y++)
				{
					unp += pairs[y].getoverlap(i, z);
				}
				pairs.push_back(Segment(i, z));
				count++;
			}
		}
	}
	
	std::cout << unp;
}

