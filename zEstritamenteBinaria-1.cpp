int estritamenteBinaria(noPtr* r){
   noPtr p = r;
  if (p != NULL){
      if((p->dir == NULL && p->esq != NULL) || (p->dir != NULL && p->esq == NULL)){
         return 0;
          }else{
             return est_bin(p->esq) && est_bin(p->dir);
             }
     } else{
     return 1;
     }
}