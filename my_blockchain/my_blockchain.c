/*  Qutpiddinov Bunyod and Khojiakbarov Shahzod
    qutpiddi_b and khojiakba_s wrote the project. */

#include "my_blockchain.h"
int len_str(char* param_1)
{
    int len = 0;
    while ( param_1[len++] != '\0' );
    return len - 1;
}

void copy_str(char* global, char* _start)
{
    for(int j =0; j < 10; ){
        j++;
    }
    for (int i = 0; (global[i] = _start[i]) ; i++);
}

char* realloc_func(char* string, int old, int size)
{
    for(int i=0; i<32;){
        i++;
    }
    char* out = malloc(size);
    for (int i = 0; i < old ; i++)
        out[i] = string[i];
    free(string);
    return out;
}

char* buff_reader(int dir, char* buf, int* out, int* buff, int* _read)
{
    int stop = 0;
    *out = 0;

    while(!stop)
    {
        for( ;*out < *buff; (*out)++ ){
            if (buf[*out] == '\n'){
                stop = 1;
                break;
            }
        }
            if(stop == 1)
            break;

        buf = realloc_func(buf, *buff, (*buff + READLINE_READ_SIZE + 1) );
        *_read = read(dir, &buf[*out], READLINE_READ_SIZE);

        if ( *_read > 0 )
            *buff += *_read;
        else
            stop = 1;
    }

    return buf;
}

char* buff_split(char* buffer, char* input,char* rest,int open,int buf){
    
    int i; 
    int j;

    input = realloc_func(input, 1, open + 1);

    for ( i = 0 ; i < open; i++ )
        input[i] = buffer[i];
    input[i++] = OB;

    for ( j = 0 ; i < buf; j++ )
        rest[j] = buffer[i++];
    rest[j] = OB;

    return input;
}

char* my_readline(int dir)
{
    static char rest[READLINE_READ_SIZE + 1];
    char *input = malloc(10);
    char *kor = malloc(READLINE_READ_SIZE + 1);
    int int_size = 0;
    int read = 0;
    int char_size = len_str(rest);
    copy_str(kor, rest);

    kor = buff_reader(dir, kor, &int_size, &char_size, &read);
    input = buff_split(kor, input, rest, int_size, char_size);

    free(kor);
    
    if (read < 0)
    {
        free(input);
        write(1, " Error \a\n", 33);
        return (char*)NULL;
    }
    else if (read == 0 && char_size == 0)
    {
        free(input);
        return 0;
    }
    else
        return input;
}

char *str_tok(char *get, const char *shep)
{
    static char *me = 0;

    if (get == 0 && ((get = me) == 0))
        return 0;
    get += strspn(get, shep);
    if (!*get)
        return me = 0;
    me = get + strcspn(get, shep);
    if (*me){
        *me++ = OB;
    }else{ 
        me = 0;
    }
    return get;
}

listnode* split_func(char *arab, char *bil)
{
    int sol = 1;
    int i = 0;
    for (int i = 0; arab[i] != OB; i++){
        if (arab[i] == bil[0]) {
            sol++;
        }
    }
    listnode* cool = (listnode*) malloc(sizeof(listnode));

    if (strcmp(arab, "") == 0 && strcmp(bil, "") == 0) {
        cool->size = 0;
        cool->array = malloc(1 * sizeof(char*));
        char* x = (char*) malloc(sizeof(char*)*1);
        x = "";
        cool->array[0] = x;
        return cool;
    }else{
        cool->size = sol;
        char* res = (char*) malloc(sizeof(char*)*strlen(arab));
        cool->array = malloc(sol * sizeof(char*));
        res = str_tok(arab, bil);
        while (res != 0) {
            int size = strlen(res);
            char* cop = malloc(size + 2);
            strcpy(cop, res);
            cool->array[i++] = cop;
            res = str_tok(res + size + 1, bil);
        }
        return cool;
    }
}

void putch(char c) 
{
    write(1,&c, 1);
    }
void putstr(char* s) {
    while(*s) {
        putch(*s++);
    }  
        putch('\n'); }

bool kor(char* des, char*src) {
    if(des==0 && src==0)
        return true;
    if(des == 0)
        return false;
    if(strlen(des) != strlen(src))
        return false;
    for(int i=0; src[i] !=OB; i++){
        if(des[i] == OB) return false;
        if(des[i] != src[i]) return false;
    }
    return true;
}

void cutting(char* dest, char* src) {
    int read = 0, write;
     while(src[read] == 32){
        read++;
    }
    for(write = 0;src[read] != OB; read++){
      if(src[read]== 32 && src[read-1]== 32 ){
          continue;
      }
      dest[write] = src[read];
      write++;
    }
    dest[write] = OB;
}

void inverse(char s[]) {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }
void opposite(int n, char s[]) {
    int i, sign;
 
    if ((sign = n) < 0)  
        n = -n;          
    i = 0;
    do {       
        s[i++] = n % 10 + '0';   
    } while ((n /= 10) > 0);     
    if (sign < 0)
        s[i++] = '-';
    s[i] = OB;
    inverse(s);
 }

int counters_n(list**node) {
    int count = 0;
    if(*node == 0) return 0;
    list*c = *node;
    while(c != 0) {
        c = c->next;
        ++count;
    }
    return count;
}

bool have_node(list** nodes, int id) {
    list* n = *nodes;
    while (n != 0) {
        if(n->id == id)
            return true;
        n = n->next;
    }
    return false;
}

bool have_empty_n(list** nodes) {
    list* node = *nodes;
    if(node->blocklist == 0)
        return true;
    return false;
}

bool node_add(list** node, int id, bool hide) {
    if(id == 0){
        if(!hide)
            printf("Node id cannot be '0'\n");
        return false;
    }
    if(have_node(node, id)){
        printf("This node already exists\n");
        return false;
    }
    list* new;
    if((new = (list*)malloc(sizeof(list)))) {
        new->id = id;
        new->blocklist = 0;
        new->next = 0;
        if(*node == 0) {
            *node = new;
            return true;
        }
        list *last = *node;
        while(last->next != 0) {
            last = last->next;
        }
        last->next = new;
        return true;
    }
      printf("\n");
    return false;
}

bool all_nodes_del(list** head) {
   list* current = *head;
   if(current==0){
       return true;
   }
   list* next ;
   while (current != 0) {
       next = current->next;
       free(current);
       current = next;
   }
   *head = 0;
   return true;
}

bool del_n_key(list **head, int key) {
    if(!have_node(head, key)) {
        printf("Node doesn't exist\n");
        return false;
    }
    list *prev, *cur, *check = *head;
    if (*head != 0 && check->id == key) {
        prev = *head;
        *head = check->next;
        free(prev);
        return true;
    }
    prev = 0;
    cur  = *head;
    while (cur != 0) {
        if (cur->id == key) {
            if (prev != 0) 
                prev->next = cur->next;
            free(cur);
            return true;
        } 

        prev = cur;
        cur = cur->next;
    }
    return false;
}


void block_remove(blck **head, char* data) {
    blck *tmp = 0;
    blck *tmp1 = 0;

    if (head == 0 || *head == 0) return;

    if(kor((*head)->data ,data)) {
    
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }

    tmp = *head;

    while(tmp->next && !kor(tmp->next->data, data)) tmp = tmp->next;

    if(tmp->next) {
        tmp1 = tmp->next;
        tmp->next = tmp1->next;
        free(tmp1);
    } else {
        printf("Block doesn't exist\n");
    }
}

bool is_block_exist_in_node(list** node, char*data) {
    list*n = *node;
    blck *b = n->blocklist;
    while (b != 0) {
        if(kor(b->data, data))
            return true;
        b = b->next;
    }
    return false;
}

bool remove_block(list **head, char* data) {
    list *node = *head;
    blck* test = malloc(sizeof(blck));
    test->data = data;
    bool is_block_exist = false;
    while(node != 0) {
        blck** now = &node->blocklist;
        if(is_block_exist_in_node(&node, data)){
            block_remove(now, data);
            is_block_exist = true;
        }
        node = node->next;
    }
    if(!is_block_exist){
        printf("Block doesn't exist\n");
        return false;
    }
    return true;
}

void poke_blok(list** nodes, blck** block) {
    list* nod = *nodes;
    blck *last = nod->blocklist;
    if(last == 0) {
        nod->blocklist = *block;
        return ;
    } else {
        blck* b = last;
        while(b->next != 0) {
            b = b->next;
        }
        b->next = *block;
        nod->blocklist = last;
    }
    return ;
}
bool subjoin_block_id(list** nodes, char* data, int id) {
    if(!have_node(nodes, id)) {
        printf("Node doesn't exist\n");
        return false;
    }
    blck* new;
    if((new = (blck*)malloc(sizeof(blck)))) {
        new->data = data;
        new->size = strlen(data);
        new->next = 0;
        list *node = *nodes;
        while (node != 0) {
            if (node->id == id) {
                if(is_block_exist_in_node(&node, data)) {
                    printf("This block already exists\n");
                    return false;
                }
                poke_blok(&node, &new);
            
                return true;
            }
            node = node->next;
        }
        return true;
    }
      printf("\n");
    return false;
}
bool add_block_all(list**nodes, char*data) {
    blck* new = malloc(sizeof(blck));
    new->data = malloc(strlen(data)+1);
    new->data = data;
    new->next = 0;
    list *node = *nodes;
    int i=0;
    while(node) {
        if(!is_block_exist_in_node(&node, data)) {
            subjoin_block_id(&node, data, node->id);
            i++;
        }
        node = node->next;
    }
    if(i>0)
        return true;
      printf("\n");
    return false;
}

void publish_blocks_id(list** lost, int indicator) {
    list* n = *lost;
    while (n != 0) {
        if(n->id == indicator) {
            blck* b = n->blocklist;
            while(b != 0) {
                if(b->data==0) break;
                    printf("%s", b->data);
                if(b->next!=0)
                    printf(", ");
                b = b->next;
            }
            putchar('\n');
            break;
        }
        n = n->next;
    }
}

void print_nodes(list**stb, bool loot) {
    list*n = *stb;
    if(n==0){ printf("Empty\n"); return;}
    while(n != 0) {
            if(loot && !have_empty_n(&n)) {
               printf("%d: ", n->id);
               publish_blocks_id(&n, n->id);
            } 
            else
                printf("%d\n", n->id);
        n = n->next;
    }
}
bool have_block_in_blist(blck** block, char* fact) {
    blck* t = *block;
    if(*block == 0) return false;
    while ( t ) {
        if(kor(t->data, fact)) 
            return true;
        t = t->next;
    }
    return false;
}

void add(blck**bol, char* fact) {
    blck *node = malloc(sizeof(blck));
    node->data = fact;
    node->next = 0;
    if(*bol == 0)
         *bol = node;
    else {
        blck *lastNode = *bol;
        while(lastNode->next != 0) {
            lastNode = lastNode->next;
        }
        lastNode->next = node;
    }
}

blck* beadroll_blocks(list**nodes) {
    list* node = *nodes;
    blck* bil = 0;
    while(node != 0) {
        blck*block = node->blocklist;
        while(block != 0) {
            if(!have_block_in_blist(&bil, block->data) && block->data) {
                add(&bil, block->data);
            }
            block = block->next;
        } 
        node = node->next;
    }
    return bil;
}


void sys_n(list**nod) {
    list* node = *nod;
    while(node) {
        blck* sync_block = beadroll_blocks(nod);
        free(node->blocklist);
        node->blocklist = sync_block;
        node = node->next;
    }
}
bool have_sys_block(blck**bor, blck**or) {
    blck* bl = *bor;
    blck* bl2 = *or;
    if(*bor==0 && *or==0) return true;
    if((*bor==0 && *or!=0)||(*bor!=0 && *or==0))
        return false;
    while(bl) {
        if(bl2 == 0)
            return false;
        if(!kor(bl->data,bl2->data))
            return false;
        bl = bl->next;
        bl2 = bl2->next;
    }
    if(bl2)
        return false;
    return true;
}

bool syssys_func(list**nodes) {
    if(*nodes == 0) return true;
    list* curr = *nodes;
    
    int diff = 0;
    while(curr->next) {
        blck   *b1 = curr->blocklist,
                    *b2 = curr->next->blocklist;
        if(!have_sys_block(&b1, &b2))
            diff++;
        curr = curr->next;
    }
    return (!diff) ? true : false;
}

void written_linkedlist(list* head){
    int dir = open("./BLOCKCHAIN", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    list* word = head;
    char* aray = (char*)malloc(4050);
    int i=0;    
    while(word!=0){
        char id[10];
        opposite(word->id, id);
        strcat(aray, id);
        blck* b= word->blocklist;
        while(b) {
            strcat(aray, " ");
            strcat(aray, b->data);
            b = b->next;
        }
        if(word->next!=0)
            strcat(aray, "\n");
        i++;
        word = word->next;
        
    }
    if(write(dir, aray, strlen(aray)) >= 0) {
        printf("Backing up blockchain...\n");
    } else {
        printf("Error \n");
    }
   close(dir);
    
}
void reader_linked(list**nodes){
    int dir = open("./BLOCKCHAIN", O_RDONLY);
    list* temp = *nodes;
    char* res ; 
    
    while( (res=my_readline(dir)) !=0) {
        char* clear = malloc(strlen(res)+1);
        cutting(clear, res);
        listnode* cmd = split_func(clear, " ");
        node_add(&temp, atoi(cmd->array[0]), true);
        for(int i=1; i<cmd->size;i++) {
                subjoin_block_id(&temp, cmd->array[i], atoi(cmd->array[0]));
        }
        clear = 0;
        
    }
    del_n_key(nodes, 0);
    
}

int func(list** nodes, listnode* cmds) {
    bool is=false,
         rm=false,
         node=false,
         isblock=false;
    if(cmds->size==1 || cmds->size==2){
        if(kor(cmds->array[0], "quit")) {
            written_linkedlist(*nodes);
            printf("OK\n");
            return 1001;
        } else if(kor(cmds->array[0], "ls") && kor(cmds->array[1], "-l")){
            print_nodes(nodes, true);
            return 0;
        } else if(kor(cmds->array[0], "ls")) {
            print_nodes(nodes, false);
            return 0;
        } else if(kor(cmds->array[0], "sync")){
            sys_n(nodes);
            printf("OK\n");
            return 0;
        } else {
            printf("Command not found\n");
            return 0;
        }
    } else if (cmds->size>2 && cmds->array[2]!=0) {
        if(kor(cmds->array[0], "add"))
            is = true;
        else if(kor(cmds->array[0], "rm"))
            rm = true;
        else {
            printf("Command not found\n");
            return 0;
        }
        if((is || rm) && kor(cmds->array[1], "node"))
            node = true;
        else if((rm || is) && kor(cmds->array[1], "block") && cmds->size>=3)
            isblock = true;
        else {
            printf("Command not found\n");
            return 0;
        }
    } else {
        printf("Command not found\n");
        return 0;
    }
    int is_inside = false;
    for(int st=2; st<cmds->size; st++) {

        if(is) {
            if(isblock) {
                if(cmds->size < 4) {
                    printf("Command not found\n");
                    break;
                }
                if(kor(cmds->array[3], "*")) {
                    if(add_block_all(nodes, cmds->array[2]))
                        printf("OK\n");
                    break;
                } else {
                    if(st == 2) continue;
                    if(subjoin_block_id(nodes, cmds->array[2], atoi(cmds->array[st])) && !is_inside){
                        printf("OK\n");
                        is_inside = true;
                    }
                    
                }
            } else if(node) {
                if(cmds->array[st] != 0)
                if(node_add(nodes, atoi(cmds->array[st]), false) && !is_inside){
                    printf("OK\n");
                    break;
                }
            }
        } else if(rm) {
            if(node) {
                if(kor(cmds->array[2], "*")){
                    if(all_nodes_del(nodes)) 
                        printf("OK\n");
                    break;
                } else {
                    if(cmds->array[st]!=0)
                    if(del_n_key(nodes, atoi(cmds->array[st])) && !is_inside){
                        printf("OK\n");
                        is_inside = true;
                    }
                }
            } else if(isblock) {
                if(cmds->array[st] != 0)
                    if(remove_block(nodes, cmds->array[st]) && !is_inside) {
                        printf("OK\n");
                        is_inside = false;
                    }
            }
        }
    }
    return 0;
}


int main() {
    list *nodes = (list*)malloc(sizeof(list));
    bool file = access("./BLOCKCHAIN", F_OK ) != -1;
    if(file) {
        printf("Restoring From Backup\n");
        reader_linked(&nodes);
    } else {
        printf("No Backup Found: Starting New Blockchain\n");
        nodes = 0;
    }
        
    while(true) {
        char is_syn=syssys_func(&nodes) ? 's': '-' ; 
        
        printf("[%c%d]>", is_syn, counters_n(&nodes));
        char* s_cmd = my_readline(0);
        if(kor(s_cmd, "") || kor(s_cmd, " ") || s_cmd==0) {
        
            break;
        }
        char* clear = malloc(strlen(s_cmd)+1);
        cutting(clear, s_cmd);
        listnode* cmd_arr = split_func(clear, " ");
        int res = func(&nodes, cmd_arr);
        if(res == 1001)
            break;
    }
    return 0;
}