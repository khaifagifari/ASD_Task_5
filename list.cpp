#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------
    first(L) = NULL;
    last(L) = NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = new elmlist;
    //-------------your code here-------------
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if (first(L) != NULL)
    {
        address Q = new elmlist;
        Q = first(L);
        next(P) = Q;
        prev(Q) = P;
        first(L) = P;
        next(last(L)) = P;
        prev(P) = last(L);
    }
    else
    {
        first(L) = P;
        last(L) = P;
        next(P) = first(L);
        prev(P) = first(L);
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (first(L) != NULL)
    {
        next(last(L)) = P;
        next(P) = first(L);
        prev(first(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
    else
    {
        insertFirst(L, P);
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = new elmlist;
    //-------------your code here-------------
    bool ketemu = false;
    P = first(L);
    do
    {
        if(info(P).ID == x.ID)
        {
            return P;
            ketemu = true;
        }
        P = next(P);
    }
    while(P!=first(L) && !ketemu);
    if (!ketemu)
    {
        return NULL;
    }
    //----------------------------------------
    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = new elmlist;
    //-------------your code here-------------
    bool ketemu = false;
    P = first(L);
    do
    {
        if(info(P).name == x.name)
        {
            return P;
            ketemu = true;
        }
        P = next(P);
    }
    while(P!=first(L) && !ketemu);
    if (!ketemu)
    {
        return NULL;
    }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (first(L)!=NULL)
    {
        if(next(first(L))!=first(L))
        {
            P = first(L);
            address Q = new elmlist;
            Q = next(first(L));
            prev(Q) = last(L);
            next(last(L))=Q;
            first(L) = Q;
            next(P) = NULL;
            prev(P) = NULL;
        }
        else
        {
            P = first(L);
            next(P) = NULL;
            prev(P) = NULL;
            first(L) = NULL;
            last(L) = NULL;
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (first(L)!=NULL)
    {
        if (first(L)!=last(L))
        {
            P = last(L);
            address Q = new elmlist;
            Q = prev(P);
            next(Q) = first(L);
            prev(first(L)) = Q;
            last(L) = Q;
            next(P) = NULL;
            prev(P) = NULL;
        }
        else
        {
            deleteFirst(L, P);
        }
    }
    else
    {
        cout << "[Kosong]" << endl;
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if (Prec!=NULL && P!=NULL)
    {
        if(next(Prec)!=first(L))
        {
            address Q = new elmlist;
            Q = next(Prec);
            next(P) = Q;
            prev(P) = Prec;
            next(Prec) = P;
            prev(Q) = P;
        }
        else if (Prec == last(L))
        {
            insertFirst(L, P);
        }
        else
        {
            insertLast(L, P);
        }
    }
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (Prec!=NULL)
    {
        if (next(Prec) == last(L))
        {
            deleteLast(L, P);
        }
        else if(next(Prec)!=first(L))
        {
            P = next(Prec);
            address Q = new elmlist;
            Q = next(P);
            next(Prec) = Q;
            prev(Q) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
        else
        {
            deleteFirst(L, P);
        }
    }
    //----------------------------------------
}

