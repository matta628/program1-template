#ifndef HEADER_VECTOR
#define HEADER_VECTOR

class Vector{
	private:
		unsigned int current_planets;
		
	public:
		Planet ** planets;
		~Vector();
		Vector();
		void insert(int, Planet *);
		Planet* read(int);
		bool remove(int);
		unsigned size();
}
#endif
