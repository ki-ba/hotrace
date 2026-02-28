#include "hotrace.h"
#include "hashmap.h"
#include <unistd.h>
#include <print_utils.h>

char *chill_strdup(const char *s, int len)
{
	char *dup;
	int j;

	j = 0;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (j < len)
	{
		dup[j] = s[j];
		j++;
	}
	dup[len] = '\0';
	return (dup);
}

// state : 0 = key | 1 = value | 2 = search mode
// TODO: MAYBE a big area if malloc is too slow

int main(void)
{
	char buf[BUF_SIZE];
	ssize_t bytes_read;
	int state;
	int hash;
	int word_len;
	char current_word[BUF_SIZE];
	char *saved_key = NULL;

	word_len = 0;
	state = 0;

	t_hashmap *map = create_hashmap(MAP_CAPACITY);

	while ((bytes_read = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
	{
		ssize_t i = 0;
		while (i < bytes_read)
		{
			if (buf[i] == '\n')
			{
				current_word[word_len] = '\0';

				if (word_len == 0 && state != 2)
				{
					state = 2;
				}
				else if (state == 1)
				{
					char *saved_value = chill_strdup(current_word, word_len);
					add_item(map, saved_key, saved_value);
					free(saved_key);
					saved_key = NULL;
					state = 0;
				}
				else if (state == 0)
				{
					saved_key = chill_strdup(current_word, word_len);
					state = 1;
				}
				else if (state == 2 && word_len > 0)
				{
					hash = hash_function(current_word, map->capacity);
					if (map->array[hash])
						ft_putstr(map->array[hash]);
					else
					{
						ft_putstr(current_word);
						ft_putstr(" : Not found.");
					}
					ft_putstr("\n");
				}

				word_len = 0;
			}
			else
			{
				current_word[word_len] = buf[i];
				word_len++;
			}
			i++;
		}
	}
	destroy_hashmap(map);
	if (saved_key)
		free(saved_key);
	return 0;
}

