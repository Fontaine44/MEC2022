# Pre-CQI - Software Engineering

## Question 3 - Bad smells (2 points)

Your coworker submits a *merge (or pull) request* and assigns you as the primary *reviewer*. It is therefore up to you to reread its code and detect possible bad smells by also considering the bad practices of the Angular framework.

a) 
```
/// This code comes from an Angular project written in Typescript
1   enum TypesDeTransport { Vehicule, Walk, Biking, }
2   interface ICoordinates {
3     longitude: number;
4     latitude: number;
5   }
6   interface Edge {
7       start: Vertice;
8       end: Vertice;
9       travelCost: Map<TypesDeTransport, number>;
10  }
11  interface Vertice {
12      id: number;
13      address: string;
14      coordinates: ICoordinates;
15  }
16  interface MapData {
17      vertices: Vertice[];
18      edges: Edge[];
19  }
20  type Path = Vertice[];
21  const BASE_URL = "https://polydiversite.com/";
22
23  @Injectable()
24  class MapGraphService {
25      private mapData: MapData;
26      private httpClient: HttpClient;
27      transportType: TypesDeTransport;
28
29      constructor() {
30          this.transportType = TypesDeTransport.Biking;
31          this.httpClient = new HttpClient();
32          this.httpClient.get(BASE_URL + "map").subscribe((mapData: MapData) => this.mapData = mapData);
33      }
34
35      findId(address: string): number {
36          const vertice = this.mapData.vertices.find((vertice) => vertice.address === address);
37          return vertice ? vertice.id : null;
38      }
39
40      getAdjacencyMatrix(transportType: TypesDeTransport): number[][] {
41          const adjacencyMatrix: number[][] = new Array<Array<number>>();
42          for (let i = 0; i < this.matrixLength; ++i) {
43              adjacencyMatrix.push(new Array<number>(this.matrixLength));
44          }
45
46          this.mapData.edges
47          .filter((edge) => edge.travelCost.has(this.transportType) ? true : false)
48          .forEach((edge) => adjacencyMatrix[edge.start.id][edge.end.id] = edge.travelCost.get(this.transportType));
49
50          return adjacencyMatrix;
51      }
52
53      public getShortestPath(startId: number, endId: number, adjancyMatrix: number[][]):Observable<Path>{
54      // Do A* search and find shortest path and takes time. (Ceci n'est pas une erreur)
55      }
56
57      private get matrixLength(): number {
58          return this.mapData.vertices.length;
59      }
60  }
61
62  @Injectable()
63  class PolyMapsService {
64
65      constructor(public mapGraphService: MapGraphService, private httpClient: HttpClient) { }
66  
67      requestTransportation(startAddress: string, endAddress: string, transportType: TypesDeTransport): Observable<Path> {
68          const startId = this.mapGraphService.findId(startAddress);
69          const endId = this.mapGraphService.findId(endAddress);
70          if (!startId || !endId) {
71              throw new Error("TRANSPORTATION - The start or the end address is not correct");
72          }
73      
74          switch (transportType) {
75              case TypesDeTransport.Biking:
76                  return this.evaluateBikingPathStrategy(startId, endId);
77              case TypesDeTransport.Vehicule:
78                  return this.evaluateVehiculePathStrategy(startId, endId);
79              case TypesDeTransport.Walk:
80                  return this.evaluateWalkPathStrategy(startId, endId);
81              default:
82                  throw new Error("TRANSPORTATION - The Transportation type is not available");
83          }
84      }
85
86      GetListOfAddresses(): Observable<string[]> {
87          return this.httpClient.get(BASE_URL + "address/all");
88      }
89
90      private evaluateBikingPathStrategy(startId: number, endId: number): Observable<Path> {
91          const map = this.mapGraphService.getAdjacencyMatrix(TypesDeTransport.Biking);
92          return this.mapGraphService.getShortestPath(startId, endId, map);
93      }
94
95      private evaluateVehiculePathStrategy(startId: number, endId: number): Observable<Path> {
96          const map = this.mapGraphService.getAdjacencyMatrix(TypesDeTransport.Vehicule);
97          return this.mapGraphService.getShortestPath(startId, endId, map);
98      }
99
100     private evaluateWalkPathStrategy(startId: number, endId: number): Observable<Path> {
101         const map = this.mapGraphService.getAdjacencyMatrix(TypesDeTransport.Walk);
102         return this.mapGraphService.getShortestPath(startId, endId, map);
103     }
104 }
105
106 @Component({
107     selector: "Poly-Maps",
108     templateUrl: "./PolyMapComponent.html",
109     styleUrls: ["./PolyMapComponent.css"]})
110 class PolyMapComponent implements OnInit {
111     transportationError: boolean = false;
112     addresses: string[];
113     formGroup: any;
114     displayedPath: ICoordinates[];
115
116     constructor(private polyMapsService: PolyMapsService) { }
117
118     ngOnInit(): void {
119         this.displayedPath = new Array<ICoordinates>();
120         this.polyMapsService.GetListOfAddresses().subscribe((addresses) => this.addresses = addresses);
121         this.formGroup = new FormGroup({
122             "startAddress": new FormControl("", Validators.required),
123             "endAddress": new FormControl("", Validators.required),
124             "transportationType": new FormControl(TypesDeTransport.Walk, Validators.required),
125         });
126     }
127
128     searchItinerary(): void {
129         if (this.formGroup.valid === false) {
130             this.transportationError = true;
131             return;
132         }
133         this.transportationError = false;
134
135         try {
136             this.polyMapsService.requestTransportation(this.startAddress, this.endAddress, this.transportType)
137             .subscribe((path: Path) => this.displayedPath = path.map((vertice) => vertice.coordinates));
138         } catch (e) {
139             this.transportationError = (e as Error).message.includes("TRANSPORTATION");
140         }
141     }
142
143     private get startAddress(): string {
144         return this.formGroup.get("startAddress").value;
145     }
146
147     private get endAddress(): string {
148         return this.formGroup.get("endAddress").value;
149     }
150
151     get transportType() {
152         return this.polyMapsService.mapGraphService.transportType;
153     }
154
155     set transportType(transportType: TypesDeTransport) {
156         this.polyMapsService.mapGraphService.transportType = transportType;
157     }
158 }
```

b)
```
/// This code comes from an Angular project written in Typescript
1   interface Task {
2       title: string,
3       description: string,
4       dueDate: Date,
5       isComplete: boolean,
6   }
7
8   interface ProjectDataModel {
9       title: string,
10      tasksList: Array<Task>,
11      subProjectsList: Array<ProjectDataModel>,
12  }
13
14  abstract class ProjectComposite {
15      protected title: string;
16      private tasksList: Array<Task>;
17
18      abstract completeProject(): void;
19      abstract findProjectWithName(title: string): ProjectComposite;
20
21      constructor(taskList: Array<Task>, title: string) {
22          this.title = title;
23          this.tasksList = taskList;
24      }
25
26      protected completeAllTasks(): void {
27          this.tasksList.forEach((task: Task) => task.isComplete = true);
28      }
29
30      completeTask(title: string): void {
31          const task: Task = this.tasksList.find((task: Task) => task.title === title);
32
33          if (!!task === true) {
34              task.isComplete = true;
35          }
36      }
37
38      addTask(task: Task): boolean {
39          if (!this.taskExists(task)) {
40              this.tasksList.push(task);
41              return true;
42          }
43          return false;
44      }
45
46      removeTask(tasktoRemove: Task): boolean {
47          const indexOfTaskToRemove: number = this.tasksList.indexOf(
48          this.tasksList.find((task: Task) => task.title === tasktoRemove.title));
49          
50          if (indexOfTaskToRemove === -1) {
51              return false;
52          }
53          
54          this.tasksList.splice(indexOfTaskToRemove, 1);
55          return true;
56      }
57
58      getTasksList(): Array<Task> {
59          return this.tasksList;
60      }
61
62      setTasksList(list: Array<Task>): void {
63          this.tasksList = list;
64      }
65
66      private taskExists(taskToAdd: Task) {
67          return this.tasksList.some(
68          (task: Task) => task.title === taskToAdd.title ? true : false);
69      }
70  }
71
72  class ProjectLeaf extends ProjectComposite {
73      constructor(data: ProjectDataModel) {
74          super(data.tasksList, data.title);
75      }
76      
77      public completeProject(): void {
78          this.completeAllTasks();
79      }
80      
81      public findProjectWithName(title: string): ProjectComposite {
82          return this.title === title ? this : undefined
83      }
84  }
85  class Project extends ProjectComposite {
86      subProjectsList: Array<ProjectComposite>;
87  
88      constructor(data: ProjectDataModel) {
89          super(data.tasksList, data.title);
90          this.subProjectsList = new Array<ProjectComposite>();
91          
92          for (const project of data.subProjectsList) {
93              this.AddSubProject(project);
94          }
95      }
96  
97      completeProject(): void {
98          this.subProjectsList.forEach((project: any) => project.completeProject());
99          this.completeAllTasks();
100     }
101 
102     findProjectWithName(title: string): ProjectComposite {
103         return this.title === title ? this :
104         this.executeOnSubProject(() => this.findProjectWithName);
105     }
106 
107     AddSubProject(subProject: ProjectDataModel): void {
108         let project: ProjectComposite;
109         
110         if (this.isLeaf(subProject)) {
111             project = new ProjectLeaf(subProject);
112             this.subProjectsList.push(project);
113         } else {
114             project = new Project(subProject);
115             this.subProjectsList.push(project);
116         }
117     }
118 
119     removeSubProject(index: number): void {
120         this.subProjectsList.splice(index, 1);
121     }
122 
123     // Template method to use recusrivity by executing a method on all subprojects
124     private executeOnSubProject<T>(functionToExecute: Function): T {
125         for (const subProject of this.subProjectsList) {
126             return functionToExecute(subProject);
127         }
128     }
129 
130     private isLeaf(project: ProjectDataModel): boolean {
131         return project.subProjectsList.length > 0;
132     }
133 }
134
135 @Injecatble()
136 class ToDoListService implements OnInit {
137     private rootProject: Project;
138     private baseUrl: string;
139
140     constructor(private http: HttpClient, public dateTimeService: DateTimeService) {
141         this.baseUrl = 'http://UnicornAndRainbow.com/api/todolist/';
142     }
143
144     ngOnInit() {
145         this.http.get<ProjectDataModel>(this.baseUrl).subscribe(
146         (root: ProjectDataModel) => this.createProjects(root));
147     }
148
149     createProjects(root: ProjectDataModel, hasLeaf?: boolean) {
150         this.rootProject = new Project(root);
151     }
152
153     findProjectWithName(title: string): ProjectComposite{
154         return this.rootProject.findProjectWithName(title);
155     }
156 }

```