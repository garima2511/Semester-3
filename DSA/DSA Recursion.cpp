#include<iostream>
#include<cmath>
using namespace std;

int fact(int n) {
	if(n == 0 || n == 1) {
		cout<<"Factorial of "<<n<<" is 1."<<endl;
		return 1;
	}
	int result = n * fact(n-1);
	cout<<"Factorial "<<n<<" * factorial "<<n-1<<" is "<<result<<endl;
	return result;
}
int fibo(int n) {
	if(n == 0) {
	return 0;
    }
	else if(n == 1) {
	return 1;
	}
	int result = fibo(n-1) + fibo(n-2);
	cout<<"Fibonacci "<<n-1<<" + "<<n-2<<" is "<<result<<endl;
	return result;
}
int GCD( int a, int b) {
	if(b == 0) {
		return a;
    }
    int result = GCD(a, a%b);
	cout<<"GCD of ("<<a<< "," <<b<<" ) is"<<result<<endl;
	return result;
}

int main() {
	int choice, num, a, b;
	cout<<"----MENU----"<<endl;
	cout<<"1. Facotrial"<<endl;
	cout<<"2. Fibonacci series"<<endl;
	cout<<"3. GCD"<<endl;
	cout<<"4. Exit."<<endl;
	
	do{
	cout<<"Enter your choice: "<<endl;
	cin>>choice;
	if(choice == 1 || choice == 2) {
		cout<<"Enter the number: "<<endl;
		cin>>num;
	}
	else {
		cout<<"Enter a and b: "<<endl;
		cin>>a>>b;
	}
		switch(choice) {
			case 1:
				cout<<"Factorial:\n "<<fact(num)<<endl;
				break;
				
			case 2:
				cout<<"Fibonacci:\n "<<fibo(num)<<endl;
				break;
				
			case 3:
				cout<<"GCD: \n"<<GCD(a,b)<<endl;
				break;
				
			case 4:
				cout<<"Exiting: "<<endl;
				break;
				
			default:
				cout<<"Invalid choice"<<endl;
				break;
		}
	} while(choice != 4);
	return 0;
}


