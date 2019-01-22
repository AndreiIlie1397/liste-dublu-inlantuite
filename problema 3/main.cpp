#include <iostream>
using namespace std;
struct nod
{
    int info;
    nod *prev,*next;
};
nod *prim, *ultim;
int nr;
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
void adaugaFinal(int x)
{
    if(prim==NULL)
    {
        prim=new nod;
        prim->info=x;
        prim->next=0;
        prim->prev=0;
        ultim=prim;
    }
    else
    {
        nod *c;
        c=new nod;
        c->info=x;
        ultim->next=c;
        c->prev=ultim;
        ultim=c;
        ultim->next=0;
    }
}
void adaugaInceput(int x)
{
    nod *p,*q=ultim;
    if(prim==NULL)
    {
        prim=new nod;
        prim->info=x;
        prim->next=0;
        prim->prev=0;
        ultim=prim;
    }
    else
    {
        while(q)
            q=q->prev;
        p=new nod;
        p->info=x;
        p->next=prim;
        prim=p;
    }
}
void stergerePrim()
{
    if(prim==NULL)
        return ;
    else
    {
        nod *aux=prim;
        prim=prim->next;
        delete aux;
    }
}
void stergereUltim()
{
    nod *q=prim, *aux;
    int x;
    x=ultim->info;
    if(prim==NULL)
        return ;
    else
    {
        if (prim->info==x)
            stergerePrim();
        else
        {
            while(q->next->info!=x && q)
                q=q->next;
            aux=q->next;
            q->next=aux->next;
            ultim=q;
            delete aux;
        }
    }
}
void afisare()
{
    nod *p=prim;
    if(prim==NULL)
        cout<<"Lista este goala";
    while(p)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}
int main()
{
    int x, a;
    cout<<"Introduceti numarul de noduri: ";
    cin>>nr;
    creare_adaugare(nr);
    afisare();
    do
    {
        cout<<endl<<"\t\tMeniu"<<endl<<endl;
        cout<<"Introduceti 1 pentru inserarea unui element la inceputul listei: "<<endl;
        cout<<"Introduceti 2 pentru inserarea unui element la sfarsitul listei: "<<endl;
        cout<<"Introduceti 3 pentru stergerea primului element: "<<endl;
        cout<<"Introduceti 4 pentru stergerea ultimului element: "<<endl;
        cout<<"Optiunea aleasa este: ";
        cin>>x;
        switch(x)
        {
        case 1:
            cout<<"Introduceti valoarea pe care doriti sa o adaugati in lista: ";
            cin>>a;
            adaugaInceput(a);
            afisare();
            break;
        case 2:
            cout<<"Introduceti valoarea pe care doriti sa o adaugati in lista: ";
            cin>>a;
            adaugaFinal(a);
            afisare();
            break;
        case 3:
            stergerePrim();
            afisare();
            break;
        case 4:
            stergereUltim();
            afisare();
            break;
        default:
            cout<<"Optiunea aleasa este incorecta. Inchideti programul si incercati din nou.";
            break;
        }
    }
    while(x!=0 && x<=4);
    return 0;
}
