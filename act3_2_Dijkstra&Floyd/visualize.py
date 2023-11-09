import os
import networkx as nx
import matplotlib.pyplot as plt

# Define the directories
tests_dir = '__tests__'
visualizations_dir = '__visualizations__'

# Create the visualizations directory if it doesn't exist
if not os.path.exists(visualizations_dir):
    os.makedirs(visualizations_dir)

# Function to read the graph from a file and create a NetworkX DiGraph (directed graph)
def create_graph_from_file(file_path):
    G = nx.DiGraph()
    with open(file_path, 'r') as file:
        nodes, _ = map(int, file.readline().split())
        G.add_nodes_from(range(1, nodes + 1))
        for line in file:
            start, end, weight = map(int, line.split())
            G.add_edge(start + 1, end + 1, weight=weight)
    return G

# Function to draw and save the directed graph with edge weights and arrows
def draw_and_save_graph(G, output_path):
    plt.figure(figsize=(10, 8))
    pos = nx.spring_layout(G)  # Compute the positions of the nodes

    # Draw nodes
    nx.draw_networkx_nodes(G, pos, node_size=700, node_color='lightblue')

    # Draw edges with larger arrows
    nx.draw_networkx_edges(G, pos, edgelist=G.edges(), edge_color='gray', arrowstyle='->',
                           arrows=True, arrowsize=30)

    # Draw labels and edge weights
    nx.draw_networkx_labels(G, pos, font_size=20, font_family='sans-serif')
    edge_weights = nx.get_edge_attributes(G, 'weight')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_weights)

    # Save the graph
    plt.axis('off')
    plt.savefig(output_path, bbox_inches='tight')
    plt.close()

# Loop through all .txt files in the tests directory and create visualizations
for filename in os.listdir(tests_dir):
    if filename.endswith('.txt'):
        file_path = os.path.join(tests_dir, filename)
        graph = create_graph_from_file(file_path)
        output_filename = os.path.splitext(filename)[0] + '.png'
        output_path = os.path.join(visualizations_dir, output_filename)
        draw_and_save_graph(graph, output_path)
