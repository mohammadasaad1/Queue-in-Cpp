#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define pb push_back
typedef long long ll ;
#define int long long
#define endl '\n'
typedef vector <long long> vi;
typedef vector <vector <long long>> vvi;
const double pi = 2 * asin (1.0);
const int MOD = 1e9 + 7;
const int N= 2e7 + 10;
template <class type>
class Queue {
    int front , rear , length , *arr , max_size;
public:
    Queue(int size)
    { max_size = size ;
        front = 0 , rear = max_size - 1 , length = 0 ;
        arr = new type [size] ;
    }
    bool isEmpty()
    {
        return length == 0 ;
    }
    bool isFull()
    {
        return length == max_size ;
    }
    void enqueue(type element)
    {
        if (isFull())
            cout << "Queue is full." ;
        else {
            rear = (rear + 1) % max_size ;
            arr[rear] = element ;
            length++ ;
        }
    }
    void dequeue()
    {
        if (isEmpty())
            cout << "Queue is empty." ;
        else {
            front = (front + 1) % max_size ;
            length-- ;
        }
    }
    type  getFront()
    {
        if (isEmpty())
            cout << "Queue is empty." ;
        else
            // the library <cassert>
            // We can use assert function thar receive a boolean Value
            // if it's true the program will continue
            // otherwise the program will stop and display where is the wrong & in which line ...
            return arr[front] ;
    }
    type getRear()
    {
        assert(!isEmpty()) ;
        return arr[rear] ;
    }
    void printQueue()
    {
        for (int i = front; i != rear + 1; i = (i + 1) % max_size) {
            cout << arr[i] << " " ;
        }
    }
    int serchIndex(type value)
    {
        int pos = -1 ;
        if(!isEmpty())
        {
            for(int i = front ; i != rear  ; i = (i + 1) % max_size)
            {
                if (arr[i] == value) {
                    pos = i ;
                    break;
                }

            }
            if(pos == -1)
                if(arr[rear] == value)
                    pos = rear ;
            return pos ;
        }
    }
};
//____________________________________SOLVE_F_________________________________________
void solve()
{
    Queue<int>s(2) ;
    s.enqueue(5) ;
    s.enqueue(6) ;
    s.dequeue() ;
    s.enqueue(5) ;
    cout << s.serchIndex(5) ;
}

//____________________________________Functions_________________________________________
bool isPrime(int n)
{
    for(int i = 2 ; i * i <= n ; i++)
        if(!(n % i))
            return 0 ;
    return 1 ;
}


//____________________________________MAIN_F_________________________________________
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef _FILE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif
    int t = 1 ;
//cin >> t ;
    while (t--)
        solve() ;
    return 0 ;
}