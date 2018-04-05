all: ui
	cd src && qmake
	cd src && make
	mv src/tracker .

ui:
	cd scripts && python create_ui.py > ../src/tracker.ui

clean:
	cd src && make clean
	rm -rf src/*.o src/Makefile src/moc_*
