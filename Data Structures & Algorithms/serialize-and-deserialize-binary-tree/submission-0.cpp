class Codec {

public:

    void dfs1(TreeNode* node,
              vector<string>& res){

        if(!node){

            res.push_back("N");

            return;
        }

        res.push_back(to_string(node->val));

        dfs1(node->left,res);

        dfs1(node->right,res);
    }

    TreeNode* dfs2(vector<string>& res,
                   int& ind){

        if(ind >= res.size()){

            return nullptr;
        }

        if(res[ind] == "N"){

            ind++;

            return nullptr;
        }

        TreeNode* node =
            new TreeNode(stoi(res[ind]));

        ind++;

        node->left = dfs2(res,ind);

        node->right = dfs2(res,ind);

        return node;
    }

    string serialize(TreeNode* root) {

        vector<string> res;

        dfs1(root,res);

        string ans = "";

        for(string s : res){

            ans += s;

            ans += ",";
        }

        return ans;
    }

    TreeNode* deserialize(string data) {

        if(data.empty()){

            return nullptr;
        }

        vector<string> res;

        string temp = "";

        for(char ch : data){

            if(ch == ','){

                res.push_back(temp);

                temp = "";
            }
            else{

                temp.push_back(ch);
            }
        }

        int ind = 0;

        return dfs2(res,ind);
    }
};