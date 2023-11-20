import java.util.HashMap;

public class LRUCache {
	HashMap<Integer, Integer> cache = new HashMap<Integer, Integer>();
	int usage[];
	int capacity, size;

	public void rearrangeUsageArray(int key) {
		for (int i = 0; i < this.size; i++) {
			int temp = this.usage[i];
			if (temp == key) {
				for (int j = i; j < this.size - 1; j++)
					this.usage[j] = this.usage[j + 1];
				this.usage[size - 1] = temp;
				return;
			}
		}
	}

	public LRUCache(int capacity) {
		this.size = 0;
		this.capacity = capacity;
		usage = new int[capacity];
	}

	public int get(int key) {
		if (this.cache.containsKey(key)) {
			this.rearrangeUsageArray(key);
			return this.cache.get(key);
		}
		return -1;
	}

	public void put(int key, int value) {
		if (this.cache.containsKey(key)) {
			this.cache.put(key, value);
			this.rearrangeUsageArray(key);
		} else if (this.size < this.capacity) {
			this.cache.put(key, value);
			this.usage[this.size] = key;
			this.size++;
		} else {
			this.cache.remove(this.usage[0]);
			this.cache.put(key, value);
			this.rearrangeUsageArray(this.usage[0]);
			this.usage[size - 1] = key;
		}
	}

	public static void main(String[] args) {
		// LRUCache l1 = new LRUCache(2);
		// l1.put(1, 1);
		// l1.put(2, 2);
		// System.out.println(l1.get(1));
		// l1.put(3, 3);
		// System.out.println(l1.get(2));
		// l1.put(4, 4);
		// System.out.println(l1.get(1));
		// System.out.println(l1.get(3));
		// System.out.println(l1.get(4));

		LRUCache l1 = new LRUCache(2);
		System.out.println(l1.get(2));
		l1.put(2, 6);
		System.out.println(l1.get(1));
		l1.put(1, 5);
		l1.put(1, 2);
		System.out.println(l1.get(1));
		System.out.println(l1.get(2));
	}
}
