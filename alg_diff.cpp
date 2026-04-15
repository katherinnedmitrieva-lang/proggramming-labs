#include <iostream>
#include <ctime>
using namespace std;

void bubbleSort(double a[], int n, bool up)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
        {
            if(up && a[j]>a[j+1]) 
            {
                double t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }

            if(!up && a[j]<a[j+1]) 
            {
                double t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
}

int main()
{	
    int n;

    cout<<"Enter n (multiple of 4): ";
    cin>>n;

    if(n%4!=0)
    {
        cout<<"n must be multiple of 4";
        return 0;
    }

    double A[100];

    srand(time(0));

    for(int i=0;i<n;i++)
        A[i]=(rand()%1000)/100.0 - 5; 

    cout<<"\nArray A:\n";

    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";

    cout<<endl;

    int rows=n/4;
    int cols=4;

    double B[100][4];

    int k=0;

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
        {
            B[i][j]=A[k];
            k++;
        }

    cout<<"\nMatrix before sorting:\n";

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<B[i][j]<<" ";

        cout<<endl;
    }

    clock_t start=clock();

    for(int i=0;i<rows;i++)
    {
        if(i%2==0)
            bubbleSort(B[i],cols,true); 
        else
            bubbleSort(B[i],cols,false); 
    }


    cout<<"\nMatrix after sorting:\n";

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<B[i][j]<<" ";

        cout<<endl;
    }

    cout<<"\nMax elements of columns:\n";

    for(int j=0;j<cols;j++)
    {
        double max=B[0][j];

        for(int i=1;i<rows;i++)
            if(B[i][j]>max)
                max=B[i][j];

        cout<<"Column "<<j<<" max = "<<max<<endl;
    }
	clock_t end=clock();
    double time=(double)(end-start)*1000/CLOCKS_PER_SEC;

    cout<<"\nTime = "<<time<<" sec"<<endl;

    cout<<"Space = "<<sizeof(A)+sizeof(B)<<" bytes"<<endl;
		
    return 0;
}