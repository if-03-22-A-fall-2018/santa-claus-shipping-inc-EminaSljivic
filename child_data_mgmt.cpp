#include <stdlib.h>

#include "child_data_mgmt.h"
#include "list.h"

struct _childDataMgmt{
  List *list;
};

ChildDataMgmt* cdm_create(){
  return (ChildDataMgmt*)list_create();
}

void cdm_add_data(ChildDataMgmt *cdm, ChildData *data){
  if(list_get_first(cdm->list)==0)
  {
    list_add(cdm->list,data);
  }

  else{
    Node* currNode=list_get_first(cdm->list);
    ChildData* currNode_data=(ChildData*)list_get_data(currNode);

    while(list_get_next(currNode)!=0 && currNode_data->city==data->city)
    {
      currNode=list_get_next(currNode);
      ChildData* currNode_data=(ChildData*)list_get_data(currNode);
    }

    list_insert_after(currNode, data);
  }
}

Node* cdm_get_sorted_data(ChildDataMgmt *cdm){
  return list_get_first(cdm->list);
}

void cdm_delete(ChildDataMgmt *cdm){
  free(cdm);
}
