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
void stergere()
{
    nod *aux, *p;
    if(marcaj==NULL)
        return ;
    else
    {
        p=marcaj;
        p=p->prev;
        aux=p->prev;
        p->prev=aux->prev;
        delete aux;
    }
}
void adauga(int x)
{
    nod *p,*q=marcaj;
    if(marcaj==NULL)
    {
        marcaj=new nod;
        marcaj->info=x;
        marcaj->next=0;
        marcaj->prev=0;
        ultim=marcaj;
    }
    else
    {
        p=new nod;
        p->info=x;
        p->prev=q->prev;
        p->next=q->next;
        q->next=p;
        q->prev=p;
    }
}
int main()
{
    int x;
    cout<<"Introduceti numarul de noduri: ";
    cin>>nr;
    creare_adaugare(nr);
    afisare(marcaj);
    ultim->next=marcaj;
    marcaj->prev=ultim;
    cout<<endl<<"Introduceti elementul pe care doriti sa il adaugati in lista: ";
    cin>>x;
    nr++;
    adauga(x);
    cout<<"Dupa adaugarea nodului in dreapta nodului marcaj:"<<endl;
    afisare(marcaj);
    stergere();
    cout<<endl;
    nr--;
    cout<<"Dupa stergerea nodului din stanga nodului marcaj:"<<endl;
    afisare(marcaj);
    return 0;
}
