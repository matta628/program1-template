#ifndef HEADER_VECTOR
#define HEADER_VECTOR

class Vector{
	private:
		~Vector();
		int current_planets;
	public:
		Vector();
		void insert(int, Planet *);
		Planet* read(int);
		bool remove(int);
		unsigned size();
}
#endif
