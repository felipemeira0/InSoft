#include <stdio.h>

struct proc {
	int atime;
	int etime;
};

int main() {
	// Variables
	int aproc = 0; // Number of processes
	int qtime = 0; // Quantum times
	int tot = 0;
	int aprocc = 0;
	int cou = 0;
	int wtime = 0;
	int ttime = 0;
	int rtime = 0;
	float avgwtime = 0;
	float avgttime = 0;
	float avgrtime = 0;
	// Read number of processes and quantum times
	scanf("%d %d", &aproc, &qtime);
	struct proc mproc[aproc+1];
	int t[aproc+1];
	// Read arrival and execution time
	for (int i = 0; i < aproc; i++) {
		scanf("%d %d", &mproc[i].atime, &mproc[i].etime);
		t[i] = mproc[i].etime;
	}
	aprocc = aproc;
	// Do a Round Robin process scheduling
	int i;
	int aa = 0;
	int res = 0;
	for (i = 0, tot = 0; aprocc != 0;) {
		if (t[i] <= qtime && t[i] > 0) {
			tot = tot + t[i];
			t[i] = 0;
			cou = 1;
		} else if (t[i] > 0) {
			t[i] = t[i] - qtime;
			tot = tot + qtime;
			if (aa == 1) {
				res++;
				aa = 0;
			}
		}
		if (t[i] == 0 && cou == 1) {
			aprocc--;
			int wa = tot - mproc[i].atime - mproc[i].etime;
			int ta = tot - mproc[i].atime;
			wtime = wtime + wa;
			ttime = ttime + ta;
			cou = 0;
		}
		if (i == aproc - 1) {
			i = 0;
			aa = 1;
		} else if (mproc[i+1].atime <= tot)
			i++;
		else
			i = 0;
	}
	// The result
	avgwtime = wtime * 1.0 / aproc;
	avgttime = ttime * 1.0 / aproc;
	avgrtime = res * 1.0 / aproc;
	printf("RR %.1f %.1f %.1f\n", avgwtime+1, avgrtime, avgttime+1);
	return 0;
}
