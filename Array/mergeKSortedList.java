public class mergeKSortedList {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0){
            return null;
        }
        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(lists.length,(a,b) -> a.val-b.val);
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;
        for(ListNode node:lists){
            if(node!=null){
                  pq.add(node);
            }
        }
        while(!pq.isEmpty()){
            tail.next = pq.poll();
            tail = tail.next;
            if(tail.next!=null){
                pq.add(tail.next);
            }
        }
        return dummy.next;
    }
}
