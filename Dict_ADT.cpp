/*
Problem Statement : Implement all the functions of a dictionary (ADT) using hashing and
 handle collisions using chaining with / without replacement. Data: Set of (key, value) pairs,
  Keys are mapped to values, Keys must be comparable Keys must be unique. Standard Operations: 
  Insert(key, value), Find(key), Delete (key) 
*/

#include<iostream>
#include<string.h>

using namespace std;

class Node{
    public:
    int chain;
    string word;
    string mean;
}obj[10];

int hash_func(string wd){
    int key = 0;
    for(int i = 0; i < wd.size(); i++)
    {
        key += wd[i];
    }
    return key%10;
}

void collision(int key, string wd, string mn){
    int i = 1;
    while (((key+1) % 10) < 10){
        if (obj[(key+i)%10].word == "-"){
            obj[(key+i)%10].word = wd;
            obj[(key+i)%10].mean = mn;
            obj[(key+i-1)%10].chain = (key+i)%10;
            break;
        }
        else{
            i++;
        }
    } 
}

void hash_ini(){
    for (int i = 0; i < 10; i++)
    {
        obj[i].word = "-";
        obj[i].mean = "-";
        obj[i].chain = -1;
    } 
}

void hash_table(){
    string wd, mn;
    cout << "Enter a word :-";
    cin >> wd;
    cout << endl;
    cout << "Enter meaning for word :-";
    cin >> mn;
    cout << endl;

    int hash_key = hash_func(wd);

    if (obj[hash_key].word == "-"){
        obj[hash_key].word = wd;
        obj[hash_key].mean = mn;
    }
    else{
        collision(hash_key, wd, mn);
    }
}

void display(){
    cout << "index" << "\t" << "word" << "\t" << "meaning" << "\t" << "chain" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t" << obj[i].word << "\t" << obj[i].mean << "\t" << obj[i].chain << endl;
    }
}

void del_key(string word){
    int key = hash_func(word);
    if (obj[key].word == word){
        obj[key].word = "-";
        obj[key].mean = "-";
        obj[key].chain = -1;
    }
    else if(obj[key].word != word){
        int target = obj[key].chain;
        while (true){
            if (obj[target].word == word){
                obj[target - 1].chain = obj[target].chain;
                obj[target].word = "-";
                obj[target].mean = "-";
                obj[target].chain = -1;
                cout << "Deletion successful" << endl;
                break;
            }
            target = obj[target].chain;
        }
    }
    else
    {
        cout << "Word not found" << endl;
    } 
}

void find(string word){
    int key = hash_func(word);
    if (obj[key].word == word){
        cout << "Found the word" << endl;
        cout << obj[key].word << "-->" << obj[key].mean << endl;
    }
    else if (obj[key].chain != -1)
    {
        int target = obj[key].chain;
        while (true)
        {
            if (obj[target].word == word){
                cout << "Found the word" << endl;
                cout << obj[target].word << "-->" << obj[target].mean << endl;
                break;
            }
        }
        target = obj[target].chain;
    }
    else
    {
        cout << "Not found" << endl;
    }
}

int main(){
    int ch;
    string del_wd;
    string src;
    hash_ini();

    do
    {
        cout << "*****Enter your choice*****" << endl;
        cout << "1. Insert data in hash table" << endl;
        cout << "2. Dispaly Hash Table" << endl;
        cout << "3. Delete word from hash table" << endl;
        cout << "4. Find word in a hash table" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice :-";
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case 1:
            cout << "Enter no of enteries you want to make :-";
            int n;
            cin >> n;
            for (int i = 0; i < n; i++){
                hash_table();
            }            
            break;
        
        case 2:
            display();
            break;
        
        case 3:
            cout << "Enter the word you want to delete :-";
            cin >> del_wd;
            del_key(del_wd);
            break;
        
        case 4:
            cout << "Enter the word you want to search :-";
            cin >> src;
            find(src);
            break;
        
        } 
    }while (ch < 5);
    cout << "Done Successfully" << endl;
    return 0;
}

/*
Output :

*****Enter your choice*****
1. Insert data in hash table
2. Dispaly Hash Table
3. Delete word from hash table
4. Find word in a hash table
5. Exit
Enter your choice :-1

Enter no of enteries you want to make :-3
Enter a word :-nice

Enter meaning for word :-good

Enter a word :-sad

Enter meaning for word :-unhappy

Enter a word :-luck

Enter meaning for word :-godbless

*****Enter your choice*****
1. Insert data in hash table
2. Dispaly Hash Table
3. Delete word from hash table
4. Find word in a hash table
5. Exit
Enter your choice :-2

index   word    meaning chain
0       -       -       -1
1       luck    godbless        -1
2       sad     unhappy -1
3       -       -       -1
4       -       -       -1
5       nice    good    -1
6       -       -       -1
7       -       -       -1
8       -       -       -1
9       -       -       -1
*****Enter your choice*****
1. Insert data in hash table
2. Dispaly Hash Table
3. Delete word from hash table
4. Find word in a hash table
5. Exit
Enter your choice :-3

Enter the word you want to delete :-luck
*****Enter your choice*****
1. Insert data in hash table
2. Dispaly Hash Table
3. Delete word from hash table
4. Find word in a hash table
5. Exit
Enter your choice :-4

Enter the word you want to search :-nice
Found the word
nice-->good
*****Enter your choice*****
1. Insert data in hash table
2. Dispaly Hash Table
3. Delete word from hash table
4. Find word in a hash table
5. Exit
Enter your choice :-5

Done Successfully

*/
