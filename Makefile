all: ui
	cd src && qmake
	cd src && make
	mv src/tracker .

ui:
	cd scripts && python create_ui.py > ../src/tracker.ui

clean:
	cd src && make clean
	rm -rf src/*.o src/Makefile src/moc_* tracker

package:
	tar czf tracker.tar.gz tracker images

install:
	install -m 775 tracker /usr/bin/tracker
	install -m 664 tracker.desktop /usr/share/applications/
	install -d -m 775 /usr/share/tracker/images
	install -m 664 images/* /usr/share/tracker/images/