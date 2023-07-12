#include <string>
#include <vector>
#include <algorithm>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int solution(vector<int> citations) {
    int H_index = 0;
    sort(citations.begin(), citations.end()); // [3,0,6,1,5] -> [0,1,3,5,6]
    // ���� ���ִ� ����? - Ư�� Index ���� ���� ũ�ų� ���� ���� ������ ����

    // �� ����ŭ index ��
    // citations[0] (0ȸ) �̻� �ο�� �� = 5��, ������ �� = 0�� . . . ����(0�� �̻� 0�� ����) ����? - O -> H_index = 0
    // citations[1] (1ȸ) �̻� �ο�� �� = 4��, ������ �� = 1�� . . . ����(1�� �̻� 1�� ����) ����? - O -> H_index = 1
    // citations[2] (3ȸ) �̻� �ο�� �� = 3��, ������ �� = 2�� . . . ����(3�� �̻� 3�� ����) ����? - O -> H_index = 3
    // citations[3] (5ȸ) �̻� �ο�� �� = 2��, ������ �� = 3�� . . . ����(5�� �̻� 5�� ����) ����? - X
    // citations[4] (6ȸ) �̻� �ο�� �� = 1��, ������ �� = 4�� . . . ����(6�� �̻� 6�� ����) ����? - X

    // ���� citations[i]ȸ �̻� �ο�� �� = (citations.size()-i) ��, ������ �� = i�� . . . 
    // ���� ( citations[i] >= citations.size()-i && citations[i] >= i )���� ���� �˻� �� �ִ밪 ����

    for (int i = 0;i < citations.size();i++)
        if (citations[i] >= citations.size() - i && citations[i] >= i) H_index = MAX(citations.size() - i, H_index);

    // �ٸ� ��� Ǯ�� ���ϱ� if�� ���� �����ϰ� + �ִ밪 ã���� �ٷ� �����ϴ� ������� �ϴ��� �װ� �� ȿ������ �� ����
    return H_index;
}