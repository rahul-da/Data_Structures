#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
typedef struct trie
{
    trie *next[26];
    bool end;
}trie;
trie* getNew()
{
    trie *p = (trie*)malloc(sizeof(trie));
    for(int i=0;i<26;i++)p->next[i]=NULL;
    p->end = false;
    return(p);
}
void insert(trie **root,string s)
{
    trie *p;
    p = (*root);
    int i=0,l = s.length();
    for(char ch:s)
    {
        if(p->next[ch-97]==NULL)
        {
            p->next[ch-97] = getNew();
            if(i==l-1)p->next[ch-97]->end=true;
        }
        i++;
        p = p->next[ch-97];
    }
}
bool search(trie *root,string s)
{
    trie *p;
    p = root;
    int i=0,l = s.length();
    for(char ch:s)
    {
        if(p->next[ch-97]==NULL)return(false);
        p = p->next[ch-97];
    }
    return(p->end);
}
void dictionary(trie *ptr,string s)
{
	if(ptr==NULL)return;
	if((ptr->end)==true)cout<<s<<endl;
	for(int i=0;i<26;i++)
	{
		if(ptr->next[i]!=NULL)
		{
			s.push_back(i+97);
			dictionary(ptr->next[i],s);
			s.pop_back();
		}
	}
}
int no_of_child(trie *ptr)
{
	if(ptr==NULL)return(0);
	int children=0;
	for(int i=0;i<26;i++)if(ptr->next[i]!=NULL)children++;
	return(children);
}
bool delete_member(trie **ptr,string s)
{
	if((*ptr)==NULL)return(false);
	string s2=s;
	if(s2.length()>0)
	{
		reverse(s2.begin(),s2.end());
		s2.pop_back();
		reverse(s2.begin(),s2.end());
	}
	if(s.length()>0)
	{
		if((*ptr)!=NULL and (*ptr)->next[s[0]-97]!=NULL and 
			delete_member(&((*ptr)->next[s[0]-97]),s2) and 
			!((*ptr)->end))
		{
			if(no_of_child(*ptr)==0)
			{
				free(*ptr);
				*ptr = NULL;
				return(true);
			}
			else return(false);
		}
	}
	else if((*ptr)->end)
	{
		if(no_of_child(*ptr)==0)
		{
			free(*ptr);
			*ptr=NULL;
			return(true);
		}
		else 
		{
			(*ptr)->end = false;
		}
	}
	return(false);
}
int main()
{
    int t;scanf("%d",&t);while(t--)
    {
        int n;
        trie *root;
        root = getNew();
        scanf("%d",&n);
        string s;
        while(n--)
        {
            cin>>s;
            insert(&root,s);
        }
        string st;
        cin>>st;
        if(search(root,st)==true)cout<<1<<endl;
        else cout<<0<<endl;
        string empty;
        dictionary(root,empty);
        cout<<s<<endl;
        delete_member(&root,s);
        dictionary(root,empty);
    }
}