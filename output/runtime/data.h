#define data_setvariableto(a,b) b = a
#define data_changevariableby(a,b) b = operator_add(a,b)

ScratchList initialiseList();
ScratchList addDataToList(ScratchList list, ScratchValue data);
ScratchList removeListItem(ScratchList list, int idx);
ScratchList insertItemAtList(ScratchList list, int idx, ScratchValue item);
ScratchValue data_itemnumoflist(ScratchValue item, ScratchList list);
ScratchValue data_listcontainsitem(ScratchValue item, ScratchList list);
ScratchValue data_itemoflist(ScratchValue index, ScratchList list);

#define data_addtolist(data, list) list = addDataToList(list, data)
#define data_deleteoflist(index, list) list = removeListItem(list, ScratchVarGetDouble(index) - 1)
#define data_deletealloflist(list) list.length = 0
#define data_insertatlist(item, index, list) list = insertItemAtList(list, ScratchVarGetDouble(index) - 1, item)
#define data_replaceitemoflist(index, item, list) list.data[(int)ScratchVarGetDouble(index) - 1] = item
#define data_lengthoflist(list) ScratchSetDouble(list.length)