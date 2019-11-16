// Problem: pace=1&num=1684
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

struct SuffixArray {
	static const int MAXL = 200000 + 5;
	static const int SIGMA = 256;
	static const int INF = 1e9;
	int size;
	int values[MAXL];
	int classes;
	int suffixArray[MAXL];
	int classID[MAXL];
	int rank[MAXL];
	int LCPArray[MAXL];
	int segmentTree[4 * MAXL];

	SuffixArray() {}

	void build(string s) {
		size = s.size();
		for (int i = 0; i < size; i++) {
			values[i] = (int)s[i];
		}
		buildSuffixArray();
		buildLCPArray();
		buildSegmentTree(1, 0, size - 1);
	}

	void countingSort(int halfLength) {
		static int currentOrder[MAXL];
		for (int i = 0; i < size; i++) {
			currentOrder[i] = (suffixArray[i] - halfLength + size) % size;
		}
		static int cnt[MAXL];
		for (int i = 0; i < classes; i++) {
			cnt[i] = 0;
		}
		for (int i = 0; i < size; i++) {
			cnt[classID[currentOrder[i]]]++;
		}
		for (int i = 1; i < classes; i++) {
			cnt[i] += cnt[i - 1];
		}
		for (int i = size - 1; i >= 0; i--) {
			suffixArray[--cnt[classID[currentOrder[i]]]] = currentOrder[i];
		}
	}

	void assignClasses(int halfLength) {
		static int newClassID[MAXL];
		classes = 1;
		newClassID[suffixArray[0]] = classes - 1;
		for (int i = 1; i < size; i++) {
			if (classID[suffixArray[i]] != classID[suffixArray[i - 1]]) {
				classes++;
			} else {
				int mid1 = (suffixArray[i - 1] + halfLength) % size;
				int mid2 = (suffixArray[i] + halfLength) % size;
				if (classID[mid1] != classID[mid2]) {
					classes++;
				}
			}
			newClassID[suffixArray[i]] = classes - 1;
		}
		for (int i = 0; i < size; i++) {
			classID[i] = newClassID[i];
		}
	}

	void buildSuffixArray() {
		values[size++] = 0;
		classes = SIGMA;
		for (int i = 0; i < size; i++) {
			suffixArray[i] = i;
			classID[i] = values[i];
		}
		int length = 1;
		while (true) {
			int halfLength = length >> 1;
			countingSort(halfLength);
			assignClasses(halfLength);
			if (length >= size) {
				break;
			}
			length <<= 1;
		}
		size--;
		for (int i = 0; i < size; i++) {
			suffixArray[i] = suffixArray[i + 1];
		}
	}
	void buildLCPArray() {
		for (int i = 0; i < size; i++) {
			rank[suffixArray[i]] = i;
		}
		int length = 0;
		for (int i = 0; i < size; i++) {
			if (length > 0) {
				length--;
			}
			if (rank[i] == 0) {
				length = 0;
				LCPArray[rank[i]] = 0;
			} else {
				int j = suffixArray[rank[i] - 1];
				while (i + length - 1 < size && j + length - 1 < size && values[i + length] == values[j + length]) {
					length++;
				}
				LCPArray[rank[i]] = length;
			}
		}
	}

	void buildSegmentTree(int now, int left, int right) {
		if (left == right) {
			segmentTree[now] = LCPArray[left];
		} else {
			int middle = (left + right) >> 1;
			int leftChild = now << 1;
			int rightChild = leftChild + 1;
			buildSegmentTree(leftChild, left, middle);
			buildSegmentTree(rightChild, middle + 1, right);
			segmentTree[now] = min(segmentTree[leftChild], segmentTree[rightChild]);
		}
	}

	int segmentTreeQuery(int now, int left, int right, int qLeft, int qRight) {
		if (right < qLeft || qRight < left) {
			return INF;
		}
		if (qLeft <= left && right <= qRight) {
			return segmentTree[now];
		}
		int middle = (left + right) >> 1;
		int leftChild = now * 2;
		int rightChild = leftChild + 1;
		int ql = segmentTreeQuery(leftChild, left, middle, qLeft, qRight);
		int qr = segmentTreeQuery(rightChild, middle + 1, right, qLeft, qRight);
		return min(ql, qr);
	}

	int getLCP(int a, int b) {
		int ra = rank[a];
		int rb = rank[b];
		if (ra == rb) {
			return size - a;
		}
		if (ra > rb) {
			swap(ra, rb);
		}
		return segmentTreeQuery(1, 0, size - 1, ra + 1, rb);
	}
}SA;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	string ab = a + "#" + b;
	SA.build(ab);

	vector <bool> ok(b.size() + 1);
	vector <int> from(b.size() + 1, -1);
	vector <vector <int> > remove(b.size() + 1);
	set <int> active;
	ok[0] = true;
	for (int i = 1; i <= b.size(); i++) {
		if (ok[i - 1]) {
			int l = SA.getLCP(0, a.size() + 1 + i - 1);
			if (l != 0) {
				remove[i + l - 1].push_back(i);
				active.insert(i);
			}
		}
		if (active.size() != 0) {
			ok[i] = true;
			from[i] = *active.begin();
		}
		for (int j = 0; j < remove[i].size(); j++) {
			active.erase(active.find(remove[i][j]));
		}
	}
	if (!ok[b.size()]) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
		vector <int> answer;
		int now = b.size();
		while (now != 0) {
            answer.push_back(now);
			now = from[now] - 1;
		}
		answer.push_back(0);
		reverse(answer.begin(), answer.end());
		for (int i = 0; i + 1 < answer.size(); i++) {
			cout << b.substr(answer[i], answer[i + 1] - answer[i]);
			if (i + 2 < answer.size()) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}
