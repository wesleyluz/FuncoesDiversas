int file(string &fileName)
{
    char newLine = '.';
    int numLines = 0;
    string text;
    ifstream openFile(fileName.c_str());

    cout << endl;

    if(!openFile)
    {
        cerr << "Error, file does not exist. " << endl;
        exit(EXIT_FAILURE);
    }

    while(getline(openFile, text, '\n'))
    {
        for(unsigned int i=0; i< text.length(); i++)
        {
            if(text.at(i) == newLine)
            {
                numLines++;
            }
        }
    }

    return numLines;
}
