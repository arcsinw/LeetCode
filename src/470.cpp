int rand10()
{
    int index = rand7() + (rand7() - 1) * 7;
    while (index > 40)
    {
        index = rand7() + (rand7() - 1) * 7;
    }

    return 1 + index % 10;
}
