#include<iostream>

using namespace std;

int s[1000]; //?????,??????


int n;

int main()

{

	while(cin>>n&&n)

	{

		int head=1;

		int tail=n; //head???,tail????n


		for(int i=1; i<=n; i++)

		{

			s[i]=i;

		}

		if(n==1)

		{

			cout<<"Discarded cards:"<<endl<<"Remaining card: 1"<<endl;

		}

		else

		{

			cout<<"Discarded cards: ";

			while(head<tail)

			{

				cout<<s[head];
				head++;

				if(head<tail)

					cout<<", ";

				if(head==tail)

					cout<<endl<<"Remaining card: "<<s[head]<<endl;

				s[++tail]=s[head];

				head++;



			}

		}

	}

	return 0;

}
