import pandas as pd
import matplotlib.pyplot as plt

df=pd.read_csv("output.csv")

algorithim=df.loc[0, 'Algorithim']
faults=df.loc[0, 'PageFaults']
hits=df.loc[0, 'Pagehits']

#bar chart
plt.figure(figsize=(6,4))
bars=plt.bar(['PageFaults', 'Pagehits'], [faults, hits], color=['tomato', 'skyblue'])

#values adding
for bar in bars:
    height=bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2, height+0.5, str(height), ha='center', fontsize=12)

plt.title(f'{Algorithm} Page Replacement Performance', fontsize=14)
plt.ylabel('Count')
plt.tight_layout()
plt.grid(axis='y', linestyle='--', alpha=0.7)

# Show the plot
plt.show()