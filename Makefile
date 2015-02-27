all: echo

echo: echo.c
	$(CC) -Os -static $? -o $@

clean:
	$(RM) echo

