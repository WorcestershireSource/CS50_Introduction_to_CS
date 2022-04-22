#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    //check if name is match for valid candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            //update ranks array
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    //take ranks which shows preferences and store in preferences array
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i; j < candidate_count - 1; j++)
        {
            preferences[ranks[i]][ranks[j + 1]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int pcount = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pcount].winner = i;
                pairs[pcount].loser = j;
                pcount++;
            }
            if (preferences[i][j] < preferences[j][i])
            {
                pairs[pcount].winner = j;
                pairs[pcount].loser = i;
                pcount++;
            }
        }
    }
    pair_count = pcount;
    printf("%i\n", pcount);
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // use pairs struc array to get win/lose pairs pairs[pair_count].winner / .loser
    //use preferences array to pull margin of victory preferences[winner][loser] = voters who prefer

    for (int i = 0; i < pair_count - 2; i++)
    {
        for (int j = 0; j < pair_count - 2; j++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[i+1].winner][pairs[i+1].loser])
            {
                int swap_win = pairs[i].winner;
                int swap_loss = pairs[i].loser;
                pairs[i].winner = pairs[i+1].winner;
                pairs[i].loser = pairs[i+1].loser;
                pairs[i+1].winner = swap_win;
                pairs[i+1].loser = swap_loss;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
//start with highest rank winner

    bool cycle = false;

    for (int o = 0; o < pair_count; o++)
    {
        for (int n = 0; n < pair_count; n++)
        {
            if (locked[pairs[o].loser][n] = true)
            {
                
            }
            // && pairs[n].loser == pairs[o].winner && locked[pairs[j].loser])
            {
                cycle = true;
            }
            if (pairs[i].loser == pairs[j].winner)
            {

            }

        }

    }


        locked[pairs[i].winner][pairs[i].lose] = true;
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}