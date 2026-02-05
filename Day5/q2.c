void merge(int* a, int n, int* b, int m, int* c, int k) {
    int i = 0, j = 0, x = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j])
            c[x++] = a[i++];
        else
            c[x++] = b[j++];
    }

    while (i < n)
        c[x++] = a[i++];

    while (j < m)
        c[x++] = b[j++];
}