#include<iostream>
#include<vector>
#include<fstream>

class unit;

template<class T>
class heap
{

private:
	int size;
	int count;
	T* arr;

public:
	heap()
	{

		size = 0;
		arr = nullptr;
		count = 0;

	}
	bool isEmpty()
	{

		return(!count);

	}
	bool Pop(T& temp)
	{
		if (count)
		{
			temp = arr[1];
			Delete(arr[1]);
			return true;
		}
		return false;
	}
	heap(int n)
	{
		size = n;
		arr = new T[size + 1];
		count = 0;

	}
	bool insert(T k)
	{
		if (arr == nullptr)
			return false;
		if (count <= size)
			arr[++count] = k;
		else
			return false;

		bool work = true;

		while (work)
		{

			int i = count;
			work = false;
			while (i >= 2 && arr[i / 2] > arr[i])
			{

				T temp = arr[i / 2];
				arr[i / 2] = arr[i];
				arr[i] = temp;
				i = i / 2;
				work = true;
			}

		}
		return true;

	}
	bool search(T key)
	{

		if (!arr)
			return;
		if (count == 0)
			return false;
		int i = 1;
		while (i <= count)
		{

			if (key == arr[i])
				return true;
			if (key >= arr[2 * i])
			{
				i = 2 * i;
			}
			else if (key >= arr[2 * i + 1])
			{

				i = 2 * i + 1;

			}

		}
		return false;
	}
	bool Delete(T key)
	{

		if (count == 0)
			return false;
		int i = 1;
		while (i <= count)
		{

			if (key == arr[i])
			{

				arr[i] = arr[count];

				count--;

				bool work = true;

				while (work)
				{

					int j = i;
					work = false;
					while (j<count)
					{
						if (2 * j <= count)
						{
							if (((2 * j) + 1) <= count)
							{

								if (arr[2 * j]<arr[2 * j + 1])
								{
									if (arr[j] > arr[2 * j])
									{

										T temp = arr[2 * j];
										arr[2 * j] = arr[j];
										arr[j] = temp;
										j = j * 2;
										work = true;
									}

								}
								else
								{
									if (arr[j] > arr[2 * j + 1])
									{

										T temp = arr[2 * j + 1];
										arr[2 * j + 1] = arr[j];
										arr[j] = temp;
										j = (j * 2) + 1;
										work = true;

									}
								}


							}
							else if (arr[2 * j] < arr[j])
							{

								T temp = arr[j];
								arr[j] = arr[2 * j];
								arr[2 * j] = temp;
								work = true;
								j = j * 2;

							}

						}
						j++;
					}

				}

				return true;
			}
			if (key >= arr[2 * i])
			{
				i = 2 * i;
			}
			else if (key >= arr[2 * i + 1])
			{

				i = 2 * i + 1;

			}

		}
		return false;

	}

	void print()
	{

		int i = 1;
		while (i <= count)
		{

			std::cout << arr[i++] << " ";

		}

	}

	void heapify(int total, int current)
	{
		if (current == 0)
			return;
		int i = current;
		int left = 2 * current;
		int right = 2 * current + 1;

		while (i <total)
		{
			int max = i;
			left = 2 * i;
			right = 2 * i + 1;
			if (left <total&&right <total)
			{

				if (arr[left] < arr[right])
					max = left;
				else
					max = right;



			}
			else if (left < total)
			{

				max = left;

			}
			if (i != max)
			{
				if (arr[i] > arr[max])
				{

					T temp = arr[max];
					arr[max] = arr[i];
					arr[i] = temp;

				}
				i = max;
			}
			else
				i = total;
		}

	}

	void minheapify(int total, int current)
	{
		if (current == 0)
			return;
		int i = current;
		int left = 2 * current;
		int right = 2 * current + 1;

		while (i <total)
		{
			int max = i;
			left = 2 * i;
			right = 2 * i + 1;
			if (left <total&&right <total)
			{

				if (arr[left] > arr[right])
					max = left;
				else
					max = right;



			}
			else if (left < total)
			{

				max = left;

			}
			if (i != max)
			{
				if (arr[i] < arr[max])
				{

					T temp = arr[max];
					arr[max] = arr[i];
					arr[i] = temp;

				}
				i = max;
			}
			else
				i = total;
		}

	}
	void heapSort()
	{

		//build heap
		int i = count / 2;
		while (i >= 0)
		{
			minheapify(count, i--);
		}

		for (int j = count; j > 0; j--)
		{

			T temp = arr[1];
			arr[1] = arr[j];
			arr[j] = temp;

			minheapify(j, 1);
		}

	}
	~heap()
	{

		if (arr)
			delete[] arr;

	}



};

template<class T>
class wtree
{

	template<typename T>
	friend std::ostream& operator<<(std::ostream&, wtree<T>);
	friend void decompress(wtree<unit> c);
	/*Node class for wiR named wtree*/
	T key;
	wtree* left;
	wtree* right;
public:
	wtree(T k=NULL, wtree*l = nullptr, wtree*r = nullptr)
	{

		key = k;
		left = l;
		right = r;

	}
	T getKey()
	{
		return key;
	}
	bool operator==(const wtree& a)
	{

		return(key==a.key);

	}
	bool operator>=(const wtree& a)
	{

		return(key >= a.key);

	}
	bool operator<=(const wtree& a)
	{

		return(key <= a.key);

	}
	bool operator>(const wtree& a)
	{

		return(key > a.key);

	}
	bool operator<(const wtree& a)
	{

		return(key < a.key);
	}
	void countNodes(int& leafCount)
	{

		if (this->left == nullptr&&this->right == nullptr)
		{
		
			++leafCount;
			return;
		}
		if (this->left)
		{
			(this->left->countNodes(leafCount));
		}
		if (this->right)
		{
			(this->right->countNodes(leafCount));
		}

	}
	void getCodes(unit* arr,int& i,unit prev)
	{
		if (!arr)
			return;
		
		if (!(this->left) && !(this->right))
		{
			(arr+i)->setch(this->key.getch());
			return;

		}
		else if (this->left&&this->right)
		{
			prev = *(arr + i);
			(arr+i)->setch(this->key.getch());
			(arr+i)->setCode('0');
			this->left->getCodes(arr,i,prev);

			i++;
			*(arr + i) = prev;
			(arr + i)->setch(arr->getch());
			(arr+i)->setCode('1');
			this->right->getCodes(arr,i,prev);

		}
		else if (this->left)
		{

			(arr+i)->setch(this->key.getch());
			(arr+i)->setCode('0');
			this->left->getCodes(arr,i,prev);

		}
		else if (this->right)
		{

			(arr+i)->setch(this->key.getch());
			(arr+i)->setCode('1');
			this->right->getCodes(arr,i,prev);

		}

	}
	void print()
	{
		std::cout << key;
		if (left)
		this->left->print();
		if (right)
		this->right->print();
	}
};

template<class T>
std::ostream& operator<<(std::ostream& write, wtree<T> obj)
{

	write << obj.key<<" ";
	return write;
}


class unit
{

	friend std::ostream& operator<<(std::ostream&, unit);
	char ch;
	int freq;
	char code[100];
	int index;
public:
	unit(char c = '\0', int f = 0)
	{
		ch = c;
		freq = f;
		index = 0;
		code[0] = '\0';
	}
	unit(unit& rhs)
	{

		this->ch = rhs.ch;
		this->freq = rhs.freq;
		this->index = rhs.index;
		for (int i = 0; i < index; i++)
			this->code[i] = rhs.code[i];

	}
	char getch()
	{
		return ch;
	}
	int getf()
	{
		return freq;
	}
	void setf(int i)
	{

		freq = i;

	}
	void setch(char i)
	{

		ch = i;

	}
	void print()
	{

		std::cout << ch << "," << freq << " ";
		for (int i = 0; i < index; i++)
			std::cout << code[i];

	}
	bool operator==(const unit& a)
	{

		return(freq == a.freq);

	}
	bool operator>=(const unit& a)
	{

		return(freq >= a.freq);

	}
	bool operator<=(const unit& a)
	{

		return(freq <= a.freq);

	}
	bool operator>(const unit& a)
	{

		return(freq > a.freq);

	}
	bool operator<(const unit& a)
	{

		return(freq < a.freq);
	}
	void setCode(char ch)
	{

		code[index++] = ch;
		code[index] = '\0';

	}
	char* getCode()
	{
		return code;
	}
	int getInd()
	{
		return index;
	}

	};

std::ostream& operator<<(std::ostream& write,unit obj)
{

	write << obj.ch<<"-"<<obj.freq<< " ";
	for (int i = 0; i < obj.index; i++)
		std::cout << obj.code[i];
	return write;
}
	int strLen(char* arr)
	{
		if (!(*arr))
			return 1;
		else
			return 1 + strLen(arr + 1);
	}
	void getStringFromBuffer(char* buffer, char*& arr)
	{
		if (!arr)
			arr = new char[strLen(buffer)];
		if (*buffer == '\0')
		{

			*arr = *buffer;
			return;

		}
		else
		{

			*arr = *buffer;
			char* temp = arr + 1;
			getStringFromBuffer(buffer + 1, temp);

		}

	}

	heap<wtree<unit>>& convertIntoHeap(std::vector<unit>& a)
	{
		heap<wtree<unit>>* Data= new heap<wtree<unit>>(a.size());

		for (int i = 0; i < a.size(); i++)
		{

			Data->insert(wtree<unit>(a[i]));

		}


		return *Data;
	}

	void updateFreq(std::vector<unit>& a, char c)
	{

		bool next = true;
		for (int i = 0; i < a.size() && next; i++)
		{

			if (a[i].getch() == c)
			{

				a[i].setf(a[i].getf() + 1);
				next = false;
			}

		}
		if (next)
			a.push_back(unit(c, 1));

	}

	bool getDataFromFile(char* filename, std::vector<unit>& a)
	{

		char ch;

		std::ifstream reader;
		reader.open(filename);
		
		if (reader.is_open())
		{
			while (!reader.eof())
			{
				ch = -1;
				reader.get(ch);
				if (ch > 0)
				{
					updateFreq(a, ch);
				}

			}

		}
		else
			return false;
		reader.close();
	}

	char* retCode(unit* codes,int size,char c)
	{

		for (int i = 0; i < size; i++)
		{

			if (codes[i].getch() == c)
				return codes[i].getCode();

		}
		return nullptr;

	}

	void writeInFile(char* filename,unit* codes,int size)
	{
		std::ifstream fin;
		std::ofstream reader;
		fin.open(filename);
		reader.open("compressed.txt");

		char ch;
		while (!fin.eof())
		{

			fin.get(ch);
			if (ch != -1)
			{
	
				char* c = retCode(codes, size, ch);
				if (c!=nullptr)
				reader << c;
			
			}
			ch = -1;

		}
		
		fin.close();
		reader.close();
	
	}


	void input(char*& filename)
	{

		char* buffer = new char[80];
		std::cout << "Enter the filename: ";
		std::cin >> buffer;
		getStringFromBuffer(buffer, filename);
		delete[] buffer;
	}

wtree<unit> BuildTree(heap<wtree<unit>>& obj)
{
	wtree<unit> b;
	wtree<unit> c;
	while (!obj.isEmpty())
	{

		obj.Pop(c);
		if (!obj.isEmpty())
		{

			obj.Pop(b);
			wtree<unit>* a = new wtree<unit>(unit('*', b.getKey().getf() + c.getKey().getf()), new wtree<unit>(c), new wtree<unit>(b));
			obj.insert(*a);

		}

	}
	return c;
}


void decompress(wtree<unit> c)
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("compressed.txt");
	fout.open("decompressed.txt");
	char ch;
	wtree<unit> a = c;
	while (!fin.eof())
	{
		fin>>ch;
		if (ch - '0')
		{
			
			c = *(c.right);

		}
		else
		{

			c = *(c.left);


		}

		if (c.right == nullptr&&c.left == nullptr)
		{

			fout << c.getKey().getch();
			c = a;
		}
	}

}


	int main()
	{
		char* filename = nullptr;
		std::vector<unit> a;
		heap<wtree<unit>> Data;
		
		input(filename);
		int size;
		getDataFromFile(filename, a);

		Data = convertIntoHeap(a);
		Data.print();
		std::cout << "\n";
		Data.heapSort();
		std::cout << "sorted Data:\n";
		Data.print();
		std::cout << "\n";
		wtree<unit> c=BuildTree(Data);
		c.print();
		std::cout << "\n";
		size = 0;
		c.countNodes(size);
		unit* arr = new unit[size];
		unit* temp = arr;
		int i = 0;
		c.getCodes(temp,i,0);
		std::cout << std::endl;
		for (int i = 0; i < size; i++)
			std::cout << arr[i]<<"\n";
		temp = arr;
		writeInFile(filename,temp, size);
		std::cout << "Compressed Data is saved to a file\n";
		std::cout << "Decompressing ... \n";
		decompress(c);
		std::cout << "Data is decompressed and saved to a file\n";
		system("pause");
		return 0;
	}