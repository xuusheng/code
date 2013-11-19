
char *my_tag_pointer;
/* xuusheng 20130422 无卡自助消费 */
if (tIpcIntTxn->cF048Ind == 'Y')
{
     if (my_tag_pointer=strstr(tIpcIntTxn->sAddtnlDataPrivate, "AO002"))
	  memcpy(sDestMsgBuf + add_tail, my_tag_pointer + 5, 2);
     /* 典型取值ASAO00214 */
}
 
add_tail += 2;
 
/* xuusheng 20130422 无卡自助消费 end */
               
/* xuusheng 20130528 begin */
if (tIpcIntTxn->sFldReservedLen[0] != ' ')
{
     memcpy(sDestMsgBuf + add_tail, tIpcIntTxn->sFldReserved + 12, 2);
     memcpy(sDestMsgBuf + add_tail + 2, tIpcIntTxn->sFldReserved + 22, 1); 
}
add_tail += 3;
if (tIpcIntTxn->sAddtnlDataPrivateLen[0] != ' ')
{
     if(my_tag_pointer=strstr(tIpcIntTxn->sAddtnlDataPrivate, "MT004"))
	  memcpy(sDestMsgBuf + add_tail, my_tag_pointer + 5, 4); 
     /* xuusheng add on 20130531 */
}
add_tail += 4;
/* xuusheng 20130528 end */
 
/* xuusheng 20130713 begin */
if (tIpcIntTxn->cF048Ind == 'Y')
{
     if (my_tag_pointer=strstr(tIpcIntTxn->sAddtnlDataPrivate, "IA008"))
	  memcpy(sDestMsgBuf + add_tail, my_tag_pointer + 5, 8);
}
add_tail += 8;
/* xuusheng 20130713 end */

                           
                        /* add by zhuwei for IC 20120525*/
                        /* *pnDestMsgLen = 757; */
                        /* mod by xuusheng 20130422 for 无卡自助消费 end*/
                        /* *pnDestMsgLen = 766; */ /* mod by xuusheng 20130422 for 无卡自助消费 */
                          *pnDestMsgLen = 774; /* mod by xuusheng 20130713 for 同城异地改造 */
                                                
