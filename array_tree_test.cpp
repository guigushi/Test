#include"array_tree.h"
#include<iostream>
#include<random>
#include<time.h>
using namespace std;
const char *const data[] = {"display\n", "update(l, r, v)\n", "query(l, r)\n"};
template<typename T>
class Test
{	
	this->
	public:
		Test(T)
};
#if 1
int main(){
	vector<int> v;
	std::default_random_engine generator;
	std::uniform_int_distribution<in> dist(0, 100000);

	while(1){
		int n;
		cout<<"Please input data scale:\n";
		cin>>n;
		v.resize(n, 0);
		for(int i = 0; i < n; i++){
			v[i] = dist(generator); // generator ramdom data
		}
		time_t time_begin, time_end;
		memset(&time_begin, 0, sizeof(time_begin));
		memset(&time_end, 0, sizeof(time_end));
		time(&time_begin);
		ArrayTree<int> arr(v);
	}
}

#else
int main(){
	vector<int> v;
	int n;
	cout<<"Please input array size:\n";
	cin>>n;
	cout<<"Please input array data:\n";
	v.resize(n, 0);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	int op = 0;
	ArrayTree<int> arrT(v);
	while(1){
		cout<<"Please Enter operation!"<<endl;
		cin>>op;
		if(op < 0 || op > 2){
			cout<<"program end!"<<endl;
			return 0;
		}
		cout<<data[op];
		int l, r, v;
		switch(op){
			case 0:
				for(int i = 0; i < n; i++){
					cout<<arrT.query(i)<<" ";
				}
				break;
			case 1:
				cin>>l;
				cin>>r;
				cin>>v;
				arrT.update(l, r, v);
				break;
			case 2:
				cin>>l;
				cin>>r;
				cout<<arrT.query(l, r);
				break;
			default:
				break;
		}
		cout<<endl;
		}
	return 0;

	}
	
#endif
