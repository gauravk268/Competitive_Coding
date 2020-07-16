    /*

     * C Program to Find All Possible Subsets of given Length in String

     */

    #include <stdio.h>

    #include <string.h>

     

    char a[20];

    int n, len, j;

     

    int main()

    {

        int i, index = 0, start = 0;

     

        printf("Enter the string\n");

        scanf("%s", a);

        n = strlen(a);

        printf("The subsets are\n");
		
		for(int j=0; j<6; j++)
        {
        	for (i  =  1;i <= j;i++)

        {

            if (index - start + 1  ==   i)

            {

                if (i  ==   len)

                {

                    for (j  =  index;j < n;j++)

                    {

                        for (i  =  start;i < index;i++)

                            printf("%c", a[i]);

                        printf("%c\n", a[j]);

                    }

                    if (start != i)

                    {

                        start++;

                        index = start;

                    }

                }

                else

                {

                    index++;

                }

            }

        }
		}
		return 0;

    }
