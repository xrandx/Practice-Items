#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

const int LEN = 256 + 5;

string cwd = "C:\\Users\\kevty\\Desktop\\";

vector<string> dict(LEN);
string src_code;
vector<string> file_dict(LEN);

class HuffmanNode{
    public:
        char content;
        int value;
        HuffmanNode *left, *right;
        string code;
        bool operator > (const HuffmanNode &rhs){
            return this->value > rhs.value;
        }
        bool operator < (const HuffmanNode &rhs){
            return this->value < rhs.value;
        }
        bool operator == (const HuffmanNode &rhs){
            return this->content == rhs.content;
        }
};


class MinHeap{

private:
    vector<HuffmanNode> heap;

public:
    int size;

    void make_heap(vector<HuffmanNode>& nodes){
        this->heap.assign(nodes.begin(), nodes.end());
        size = this->heap.size();
        for (int i = size / 2 - 1; i >= 0; i--)
            down(i);
    }

    void push(HuffmanNode tmp){
        this->heap.push_back(tmp);
        size++;
        up(size - 1);
    }

    HuffmanNode pop(){
        if(size <= 0){
            cout << "size错误" << endl;
        }
        else{
            HuffmanNode result = this->heap[0];
            this->heap[0] = this->heap[size - 1];
            this->heap.pop_back();
            size--;
            down(0);
            return result;
        }
    }

    void down(int index){
        if(index < 0){
            cout << "index错误" << endl;
        }
        else{
            HuffmanNode temp = this->heap[index];
            index = index * 2 + 1;
            while (index < size)
            {
                if (index + 1 < size && this->heap[index] > this->heap[index + 1]) index++;
                if (this->heap[index] > temp) break;
                else
                {
                    this->heap[(index - 1) / 2] = this->heap[index];
                    index = index * 2 + 1;
                }
            }
            this->heap[(index - 1) / 2] = temp;
        }
    }

    void up(int index){
        if(index >= size){
            cout << "index, size错误" << endl;
        }
        else{
            HuffmanNode temp = this->heap[index];
            while (index > 0 && temp < this->heap[(index - 1) / 2])
            {
                this->heap[index] = this->heap[(index - 1) / 2];
                index = (index - 1) / 2;
            }
            this->heap[index] = temp;
        }
    }

    void display(){
        cout << "----------------------" << endl;
        cout << "最小堆：" << endl;
        for(int i = 0; i < this->heap.size(); i++){
            cout << this->heap[i].content << "|" << this->heap[i].value << endl;
        }
        cout << "----------------------" << endl;
    }

};

// 读取源文件 
string loadFile(){
    string file_path = cwd + "src.txt";
    cout << file_path;
    FILE *fp_read = fopen(file_path.c_str(),"r");
    if(fp_read == NULL){
        cout << "文件读取错误" << endl;
        return "";
    }

    string buff;
    char ch;
    while(1){
        ch = fgetc(fp_read);
        if(ch == EOF && ch)
            break;
        else
            buff.push_back(ch);
    }
    fclose(fp_read);
    return buff;
}

// 根据读取数据计算字符频率 
vector<HuffmanNode> calculate_times(){
    string buff = loadFile();
    cout << "----------------------" << endl;
    cout << "读取数据" << endl;
    cout << "----------------------" << endl;
    vector<HuffmanNode> array(LEN);
    HuffmanNode node;

    for(int i = 0; i < buff.size(); i++){
        int key = buff[i];
        if(array[key].value != 0)
            array[key].value++;
        else{
            node.content = buff[i];
            node.value = 1;
            array[key] = node;
        }
    }

    for(int i = 0; i < array.size();){
        if(array[i].value == 0){
            array.erase(array.begin() + i);
        }
        else{
            i++;
        }
    }
    cout << "----------------------" << endl;
    cout << "字符频率表" << endl;
    for(int i = 0; i < array.size(); i++){
        cout << array[i].content << "|"<< array[i].value << endl;
    }
    cout << "----------------------" << endl;
    return array;
}


// 根据字符频率建立哈夫曼树 
void makeHuffmanTree(vector<HuffmanNode> alphabet, HuffmanNode huffman_tree[]){
    MinHeap min_heap;
    min_heap.make_heap(alphabet);
    min_heap.display();
    int cnt = 1;
    while(min_heap.size >= 2){
        HuffmanNode head;
        huffman_tree[cnt] = min_heap.pop();
        head.left = &huffman_tree[cnt];
        cnt++;
        huffman_tree[cnt] = min_heap.pop();
        head.right = &huffman_tree[cnt];
		cnt++;
        head.value = head.left->value + head.right->value;
        min_heap.push(head);
    }
    huffman_tree[0] = min_heap.pop();
    return;
}

// 递归遍历哈夫曼树 
void calculate_code(HuffmanNode *head, string code){
	if(!head->left && !head->right){
		dict[head->content] = code;
	}
	else{
		if(head->left){
	        string tmp = code + '0';
			calculate_code(head->left, tmp);
	    }
	    if(head->right){
	        string tmp = code + '1';
			calculate_code(head->right, tmp);
	    }
	}
	return;
}

// 计算哈夫曼编码 
void makeHuffmanCode(HuffmanNode *top){
    cout << "----------------------" << endl;
    cout << "遍历哈夫曼树" << endl;	
    dict = vector<string>(LEN);
    calculate_code(top, string(""));
    cout << "----------------------" << endl;
    cout << "编码列表" << endl;	
	for(int i = 0; i < LEN; i++){
		if(!dict[i].empty())
			cout << char(i) << "|" << dict[i] << endl;
	}
	cout << "----------------------" << endl;
}

// 保存译码字典和数据 
void saveFile(){
    string fileTemp = loadFile();
    
	FILE *fp_write = NULL;
    string file_path = cwd + "src.dat";
	fp_write = fopen(file_path.c_str(), "w");
	if(fp_write == NULL){
        cout << "文件写入错误" << endl;
        return;
    }
    cout << "保存文件" << endl;
    // head
	for(int i = 0; i < LEN; i++){
		if(!dict[i].empty()){
			fprintf(fp_write, "%c:%s\n", char(i), dict[i].c_str());
		}
	}
	// code
	fprintf(fp_write, "||\n");
	for(int i = 0; i < fileTemp.size(); i++){
		int literal = fileTemp[i];
		fprintf(fp_write, "%s", dict[literal].c_str());
	}
	fclose(fp_write);
}

// 载入译码字典和数据 
void loadCode(){
	FILE *fp_read = NULL;
    string file_path = cwd + "src.dat";
	fp_read = fopen(file_path.c_str(), "r");
	if(fp_read == NULL){
        cout << "文件读取错误" << endl;
        return;
    }
    cout << "----------------------" << endl;
    cout << "读取文件" << endl;
    char now, previous, previous2;
    int start;
    // head
    cout << "----------------------" << endl;
    cout << "译码表" << endl;
    while(1){
		previous = fgetc(fp_read);
		now = fgetc(fp_read);
		if(now == ':'){
			string code;
			while(1){
				now = fgetc(fp_read);
				if(now == '\n')
					break;
				code += now;
			}
			file_dict[previous] = code;
			cout << previous << "|" << code << endl;
		}
		else if(now == '|' && previous == '|'){
			break;
		}
	}
    // body
    fgetc(fp_read);
    cout << "----------------------" << endl;           
    cout << "数据部分" << endl;
    src_code.clear();
    while(1){		
		now = fgetc(fp_read);
		if(now == EOF)
			break;
		src_code += now;		
	}
    cout << src_code;
}


// 从译码字典构建哈夫曼树， 根据哈夫曼树翻译源码 
void makeHuffmanTreeFromFile(){
	HuffmanNode* head = new HuffmanNode();
	HuffmanNode* p;
	
	for(int i = 0; i < LEN; i++){
		if(!file_dict[i].empty()){
			p = head;
			int last = file_dict[i].size() - 1;
			
			for(int j = 0; j <= last; j++){
				char ch = file_dict[i][j];
				if(ch == '0'){
					if(!p->left){
						p->left = new HuffmanNode();
						if(j == last){
							p->left->content = char(i);
							break;
						}
					}
					p = p->left;
				}
				else {
					if(!p->right){
						p->right = new HuffmanNode();
						if(j == last){
							p->right->content = char(i);
							break;
						}
					}
					p = p->right;
				}
			}
		
		}
	}
	
	p = head;
	string result;
	for(int i = 0; i < src_code.size(); i++){
		if(!p->left && !p->right){
			result += p->content;
			p = head;
		}
		if(src_code[i] == '0'){
			p = p->left;
		}
		else{
			p = p->right;
		}
	}
	cout << "----------------------" << endl;           
    cout << "翻译" << endl;
	cout << result << endl;
	FILE *fp_write = NULL;
	fp_write = fopen("译文-src.txt", "w");
	if(fp_write == NULL){
        cout << "文件写入错误" << endl;
        return;
    }
    cout << "保存文件" << endl;
	fprintf(fp_write, "%s", result.c_str());
}


int main(){
	// 编码 
    vector<HuffmanNode> alphabet_times = calculate_times();
    HuffmanNode huffman_tree[LEN];
    makeHuffmanTree(alphabet_times, huffman_tree);
    makeHuffmanCode(huffman_tree);
    saveFile();

    // 译码
	loadCode(); 
	makeHuffmanTreeFromFile();
	system("pause");
    return 0;
}
