Andrew Park and Zhiye Lu
Module 101: Lists for a Movie

/*The robot successfully takes 10 pictures, displays
them in forward order, and then displayed them in reverse order
*/

void addPicture(movieList * first, movieList * last, Picture frame);

int main(void) {

	printf("Starting program:  ");
	rConnect("/dev/rfcomm0");
	rSetForwardness("fluke-forward");

	printf("program asking Scribbler 2 to take and display pictures\n");

	movieList movie = NULL;
	movieList last = NULL;
	int numPics = 0;

	while (numPics <= 10)
	{

		Picture frame = rTakePicture();
		rTurnLeft(0.3, 0.3);

		addPicture(&movie, &last, frame);

		if (numPics == 10)
		{
			printForward(movie);
			printReverse(movie);
		}

		numPics++;
	}

	printf("Closing connection to robot....");
	rDisconnect();
	printf(" finished.\n\n");
}


void addPicture(movieList * first, movieList * last, Picture frame)
{
	movieList newNode = (movieList)malloc(sizeof(movieNode));
	newNode->pic = frame;
	newNode->next = NULL;

	if (*first == NULL)
	{
		*first = newNode;
		*last = newNode;
	}
	else
	{
		(*last)->next = newNode;
		*last = newNode;
	}
}
