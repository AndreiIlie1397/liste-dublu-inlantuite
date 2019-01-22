#include <iostream>
using namespace std;
struct nod
{
    char info;
    nod* next,*prev;
};
nod* prim, *ultim;
void creare_adaugare(int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        if(prim==NULL)
        {
            prim=new nod;
            cout<<"Valoarea de adaugat in lista: ";
            cin>>prim->info;
            prim->next=0;
            prim->prev=0;
            ultim=prim;
        }
        else
        {
            nod *c;
            c=new nod;
            cout<<"Valoarea de adaugat in lista: ";
            cin>>c->info;
            ultim->next=c;
            c->prev=ultim;
            ultim=c;
            ultim->next=0;
        }
    }
}
void afisare()
{
    nod* p=prim;
    if(prim==NULL)
        cout<<"Lista este goala";
    while(p)
    {
        cout<<p->info;
        p=p->next;
    }
    cout<<endl;
}
void afisareBordura(int n)
{
    int i;
    nod *p=prim;
    if(n==0)
        cout<<"Nu exista margine."<<endl;
    else
        cout<<"Marginea este: ";
    for(i=1; i<=n; i++)
        {
            cout<<p->info;
            p=p->next;
        }
}
void bordura(int n)
{
    int i, bordura=0, x;
    nod *p=prim, *q=prim, *aux;
    while(q->next)
        q=q->next;
        x=n-1;
    while(x!=0)
    {
        p=prim;
        aux=q;
        for(i=1; i<=x; i++)
            aux=aux->prev;
        bordura=0;
        for(i=1; i<=x-1; i++)
        {
            if(p->info==aux->info)
                bordura++;
            aux=aux->next;
            p=p->next;
        }
        if(bordura!=x)
            x--;
        if(bordura==x)
            break;
    }
        afisareBordura(bordura);
}

int main()
{
    int nr;
    cout<<"Introduceti numarul de noduri: ";
    cin>>nr;
    creare_adaugare(nr);
    afisare();
    bordura(nr);
    return 0;
}
