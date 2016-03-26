sealed abstract class Heap[+A] { def rank: Int }
case object EmptyHeap extends Heap[Nothing] { def rank = 0}
case class NonEmptyHeap[A](rank: Int, element: A, left: Heap[A], right: Heap[A]) extends Heap[A]

object Heap {
  def apply[A](x: A): Heap[A] =
    this(x, EmptyHeap, EmptyHeap)

  def apply[A](x: A, a: Heap[A], b: Heap[A]): Heap[A] =
    if (a.rank > b.rank)
      NonEmptyHeap(b.rank + 1, x, a, b)
    else
      NonEmptyHeap(a.rank + 1, x, b, a)

  def merge[A <% Ordered[A]](a: Heap[A], b: Heap[A]): Heap[A] =
    (a, b) match {
      case (x, EmptyHeap) => x
      case (EmptyHeap, x) => x
      case (x: NonEmptyHeap[A], y: NonEmptyHeap[A]) =>
        if (x.element >= y.element)
          Heap(x.element, x.left, merge(x.right, y))
        else
          Heap(y.element, y.left, merge(x, y.right))
    }

  def toList[A <% Ordered[A]](heap: Heap[A]) =
    toListWithMemory(List(), heap)

  @annotation.tailrec
  def toListWithMemory[A <% Ordered[A]](memo: List[A], heap: Heap[A]): List[A] =
    heap match {
      case EmptyHeap => memo
      case x: NonEmptyHeap[A] =>
        toListWithMemory(x.element :: memo, merge(x.left, x.right))
    }

  def heapSort[A <% Ordered[A]](xs: Seq[A]): Seq[A] =
    toList(xs.foldLeft(EmptyHeap: Heap[A])((memo, x) => merge(Heap(x), memo)))
}

object HeapSortTest {
  def main(args: Array[String]) = {
    Heap.heapSort(Range(1, 1000000))
    System.out.println("Done!")
  }
}
