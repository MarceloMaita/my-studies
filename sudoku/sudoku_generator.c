#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 9
#define UNASSIGNED 0

int grid[N][N];

/* Utility: print grid */
void print_grid(int g[N][N]) {
    for (int r = 0; r < N; ++r) {
        if (r % 3 == 0 && r != 0) printf("---------------------\n");
        for (int c = 0; c < N; ++c) {
            if (c % 3 == 0 && c != 0) printf("| ");
            printf("%d ", g[r][c] ? g[r][c] : 0);
        }
        printf("\n");
    }
}

/* Check if num can be placed at r,c */
int is_safe(int g[N][N], int r, int c, int num) {
    for (int x = 0; x < N; ++x) {
        if (g[r][x] == num) return 0;
        if (g[x][c] == num) return 0;
    }
    int sr = (r/3)*3, sc = (c/3)*3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (g[sr+i][sc+j] == num) return 0;
    return 1;
}

/* Shuffle an array of length len in place */
void shuffle(int *arr, int len) {
    for (int i = len-1; i > 0; --i) {
        int j = rand() % (i+1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

/* Backtracking fill to produce a full valid grid (randomized) */
int fill_grid(int g[N][N]) {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (g[r][c] == UNASSIGNED) {
                int nums[N];
                for (int i = 0; i < N; ++i) nums[i] = i+1;
                shuffle(nums, N);
                for (int i = 0; i < N; ++i) {
                    int num = nums[i];
                    if (is_safe(g, r, c, num)) {
                        g[r][c] = num;
                        if (fill_grid(g)) return 1;
                        g[r][c] = UNASSIGNED;
                    }
                }
                return 0; /* no number fits -> backtrack */
            }
        }
    }
    return 1; /* filled */
}

/* Find unassigned position, returns 1 if found and sets row/col */
int find_unassigned(int g[N][N], int *row, int *col) {
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            if (g[r][c] == UNASSIGNED) {
                *row = r; *col = c;
                return 1;
            }
    return 0;
}

/* Count solutions up to limit. Returns number of solutions found (but early exits if >= limit) */
int count_solutions_limit(int g[N][N], int limit) {
    int row, col;
    if (!find_unassigned(g, &row, &col)) return 1; /* completed -> one solution found */

    int count = 0;
    for (int num = 1; num <= 9; ++num) {
        if (is_safe(g, row, col, num)) {
            g[row][col] = num;
            int res = count_solutions_limit(g, limit);
            if (res > 0) {
                count += res;
            }
            g[row][col] = UNASSIGNED;
            if (count >= limit) return count; /* early exit */
        }
    }
    return count;
}

/* Wrapper that returns 0,1, or >=2 (we'll cap at 2) */
int has_unique_solution(int g[N][N]) {
    int copy[N][N];
    memcpy(copy, g, sizeof(copy));
    int cnt = count_solutions_limit(copy, 2);
    return (cnt == 1);
}

/* Remove numbers to create a puzzle while preserving uniqueness.
   num_removals: target number of cells to remove (may stop earlier if uniqueness fails).
   symmetric: if 1, remove cells in symmetric pairs (180-degree symmetry).
*/
void make_puzzle(int g[N][N], int num_removals, int symmetric) {
    /* Create an index list of all cells and shuffle */
    int cells[N*N];
    for (int i = 0; i < N*N; ++i) cells[i] = i;
    shuffle(cells, N*N);

    int removed = 0;
    for (int idx = 0; idx < N*N && removed < num_removals; ++idx) {
        int cell = cells[idx];
        int r = cell / N, c = cell % N;

        if (g[r][c] == UNASSIGNED) continue;

        int backup = g[r][c];
        int backup_sym = -1;
        int sr = -1, sc = -1;

        if (symmetric) {
            sr = N-1 - r;
            sc = N-1 - c;
            if (!(sr==r && sc==c)) {
                backup_sym = g[sr][sc];
                if (backup_sym == UNASSIGNED) continue;
            }
        }

        g[r][c] = UNASSIGNED;
        if (symmetric && !(sr==r && sc==c)) g[sr][sc] = UNASSIGNED;

        if (has_unique_solution(g)) {
            /* keep removal */
            removed += (symmetric && backup_sym != -1 && !(sr==r && sc==c)) ? 2 : 1;
        } else {
            /* revert */
            g[r][c] = backup;
            if (symmetric && backup_sym != -1 && !(sr==r && sc==c)) g[sr][sc] = backup_sym;
        }
    }

    printf("Requested removals: %d; Actual removed (approx): %d\n", num_removals, removed);
}

/* Convenience: copy grid */
void copy_grid(int src[N][N], int dst[N][N]) {
    memcpy(dst, src, sizeof(int)*N*N);
}

int main(void) {
    srand((unsigned) time(NULL));

    /* 0 fill grid with zeros */
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            grid[r][c] = UNASSIGNED;

    /* Fill full solution */
    if (!fill_grid(grid)) {
        fprintf(stderr, "Failed to generate full grid\n");
        return 1;
    }

    int solution[N][N];
    copy_grid(grid, solution);

    printf("Full solution:\n");
    print_grid(solution);
    printf("\n");

    /* Create puzzle */
    int NUM_REMOVALS = 45; /* tune: more removals => fewer clues => harder (typical puzzles 22..36 clues) */
    int SYMMETRIC = 1; /* 1 for 180-degree symmetry */

    make_puzzle(grid, NUM_REMOVALS, SYMMETRIC);

    printf("Puzzle (0 = empty):\n");
    print_grid(grid);
    printf("\n");

    /* Optionally show solution */
    printf("Solution (for verification):\n");
    print_grid(solution);

    return 0;
}
