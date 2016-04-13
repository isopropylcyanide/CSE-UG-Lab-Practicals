all: create_manifest compile run

create_manifest:
	@printf "Main-Class: main_tester\n" > classes/manifest.txt

compile:
	@javac -d classes/ source/interaction_graph.java
	@cd classes; \
	jar -cvmf manifest.txt igraph.jar *.class >/dev/null;

run:
	@cd classes; \
	java -jar igraph.jar $(nodes);

clean:
	@rm classes/*.*
