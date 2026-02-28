#include "hotrace.h"
#include "hashmap.h"
#include <unistd.h>

char	*chill_strdup(const char *s, int len)
{
	char	*dup;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	for (int j = 0; j < len; j++) {
	dup[j] = s[j];
	}
	dup[len] = '\0';
	return dup;
}

// state : 0 = key | 1 = value | 2 = search mode
//TODO: MAYBE a big area if malloc is too slow

int main()
{
    char buf[BUF_SIZE];
    ssize_t bytes_read;
    int state;
    int word_len;
    char current_word[BUF_SIZE];
    char *saved_key = NULL;

    word_len = 0;
    state = 0;
    while ((bytes_read = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {

	ssize_t i = 0;
	while (i < bytes_read) {

	    if (buf[i] == '\n') {
		current_word[word_len] = '\0';

		if (word_len == 0 && state != 2) {
		    state = 2;
		} else if (state == 1) {
		    char *saved_value = chill_strdup(current_word, word_len);
		    // TODO: HASH the saved_key && insert saved_value
			free(saved_key);
			free(saved_value);
		    state = 0;
		} else if (state == 0) {
		    saved_key = chill_strdup(current_word, word_len);
		    state = 1;
		} else if (state == 2 && word_len > 0) {
		    // TODO: Search current word in the hash map
		}

		word_len = 0;

	    } else {
		current_word[word_len] = buf[i];
		word_len++;
	    }

	    i++;
	}
    }
    return 0;
}
