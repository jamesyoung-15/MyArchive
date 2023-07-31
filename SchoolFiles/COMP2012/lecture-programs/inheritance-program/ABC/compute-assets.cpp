/* File: compute-assets.cpp */
double compute_total_worth(const Personal_Asset* asset[], int num_assets)
{
    double total_worth = 0.0;

    for (int i = 0; i < num_assets; i++)
        total_worth += assets[i]->compute_net_worth();

    return total_worth;
}
