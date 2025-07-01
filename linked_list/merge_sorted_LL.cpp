node* solve(node* first,node* second)
{
    if(first->next==NULL)
 {
  first->next=second;
  return first;   
 }
 node* curr1=first;
 node* next1=first->next;
 node* curr2=second;
 node* next2=curr2->next;
 

 while(next1!=NULL && curr2!=NULL){
     if(curr1->val<=curr2->val && next1->val >= curr2->val)
     {
         curr1->next=curr2;
         next2=curr2->next;
         curr2->next=next1;
         curr1=curr2;
         curr2=next2;
     }
     else
     {
         curr1=next1;
         next1=next1->next;
         if(next1==NULL)
         {
             curr1->next=curr2;
             return first;
         }
     }
 }
 return first;
}
node* mergelist(node* head1,node* head2)
{
    if(head2==NULL)
    return head1;
    if(head1==NULL)
    return head2;
    if(first->data<=second->data)
    return solve(first,second)
    else
    return solve(second,first);
}