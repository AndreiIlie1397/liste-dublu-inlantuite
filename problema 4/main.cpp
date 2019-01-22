#include<iostream>
using namespace std;

struct nod
{
    int info;
    nod *next,*prev;
};
nod *marcaj, *ultim;
int nr;
void creare_adaugare(int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        if(marcaj==NULL)
        {
            marcaj=new nod;
            cout<<"Introduceti nodul marcaj: ";
            cin>>marcaj->info;
            marcaj->next=0;
            marcaj->prev=0;
            ultim=marcaj;
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
void afisare(nod *c)
{
    for(int i=1; i<=nr; i++)
    {
        cout<<c->info<<" ";
        c=c->next;
    }
}
void adaugaPePozitie(int k,int x)
{
    int i;
    nod *p,*q=marcaj;
        for(i=1; i<=k-2; i++)
            q=q->next;
        p=new nod;
        p->info=x;
        p->prev=q->prev;
        p->next=q->next;
        q->next=p;
        q->prev=p;
}
void stergereNod(int x)
{
    if(marcaj==NULL)
        return ;
    else
    {
        if (marcaj->info==x)
        {
            nod *aux=marcaj;
            marcaj=marcaj->next;
            delete aux;
        }
        else
        {
            nod *q=marcaj;
            while (q->next->info!=x)
                q=q->next;
            nod *aux=q->next;
            q->next=q->next->next;
            delete aux;
        }
    }
}
int main()
{
    int a, k, x;
    cout<<"Introduceti numarul de noduri: ";
    cin>>nr;
    creare_adaugare(nr);
    ultim->next=marcaj;
    marcaj->prev=ultim;
    cout<<"Introduceti valoarea pe care doriti sa o adaugati in lista: ";
    cin>>a;
    cout<<"Introduceti pozitia pe care doriti sa adaugati valoarea "<<a<<": ";
    cin>>k;
    adaugaPePozitie(k, a);
    nr++;
    afisare(marcaj);
    cout<<endl<<"Introduceti valoarea pe care doriti sa o stergeti din lista: ";
    cin>>x;
    stergereNod(x);
    nr--;
    afisare(marcaj);
    return 0;
}
