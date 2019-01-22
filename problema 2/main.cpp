#include <iostream>
using namespace std;
struct nod
{
    int val, prior;
    nod *next;
};
nod *prim, *ultim;
int nr;
void inserare(int x, int p)
{
    nod *c, *q=prim;
    if(prim==NULL)
    {
        prim=new nod;
        prim->val=x;
        prim->prior=p;
        prim->next=NULL;
        ultim=prim;
    }
    else
    {
        while((q->next!=NULL) && (q->next->prior<=p))
            q=q->next;
        c=new nod;
        c->val=x;
        c->prior=p;
        if(q->next==NULL)
        {
            q->next=c;
            c->next=NULL;
        }
        else
        {
            c->next=q->next;
            q->next=c;
        }
    }
}
void extragere(int p)
{
    nod *q=prim;
    if(prim==NULL)
    {
        cout<<"Lista este goala!"<<endl;
        return ;
    }
        if(p==1)
        {
            nod *aux=prim;
            prim=prim->next;
            delete aux;
        }
        else
        {
             while(q->next->prior!=p)
            q=q->next;
            nod *aux=q->next;
            q->next=q->next->next;
            delete aux;
        }
}
void afisare()
{
    nod *p=prim;
    cout<<endl;
    if(p==NULL)
    {
        cout<<"Coada este goala!"<<endl;
        return ;
    }
    while(p!=NULL)
    {
        cout<<"Valoare: ";
        cout <<p->val<<" "<<endl;
        cout <<"Prioritate: ";
        cout <<p->prior<<" "<<endl<<endl;
        p=p->next;
    }
}
int main()
{
    int i, x, pr, c;
    cout<<"Introduceti numarul de elemente: ";
    cin>>nr;
    for (i=1; i<=nr; i++)
    {
        cout<<"Valorea: ";
        cin>>x;
        cout<<"Prioritatea: ";
        cin>>pr;
        cout<<endl;
        inserare(x, pr);
    }
    do
    {
        cout<<"Ce operatiune doriti sa faceti?"<<endl;
        cout<<"1 - Inserarea unui element nou."<<endl<<"2 - Eliminarea unui element"<<endl;
        cout<<"Optiunea aleasa este: ";
        cin>>c;
        if(c==1)
        {
            cout<<"Introduceti valoarea elementului: ";
            cin>>x;
            cout<<"Introduceti prioritatea elementului: ";
            cin>>pr;
            inserare(x, pr);
            afisare();
        }
        if(c==2)
        {
            cout<<"Introduceti prioritatea din care se va extrage primul element: ";
            cin>>pr;
            extragere(pr);
            afisare();
        }
    }
    while(c!=0 && c<=2);
    return 0;
}
