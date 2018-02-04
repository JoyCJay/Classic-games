#include "stdafx.h"
#include "dataStruct.h"

UINT8   computer_side = CHESS_BLACK;
UINT8   max_depth = 4;

UINT8   cur_depth = 0;

UINT8   cur_step =0;
UINT16   step_array[64];

UINT8   g_iGameLevel = LEVEL_LOW; //游戏难度等级
const  UINT8 depth1[]={6, 7, 8};
const  UINT8 depth2[]={5, 6, 7};

/*找出所有在水平方向受保护的obcolor方的棋子，并累计分数*/
INT16 scan_horiz_aixes(board_type *board_ptr, UINT8 obcolor)
{
	/*扫描8个水平方向*/
	INT16 score=0;
	UINT8 *cur_ptr, *stop_ptr;
	UINT8  piece[4][2];
	UINT8 count=0, tmpscore;
	UINT8 bFull;
	for(UINT8 row=1; row<9; row++)
	{
        tmpscore = (row == 1 || row == 8) ? 10:2;
		cur_ptr = &board_ptr->board[row][1];
		stop_ptr= &board_ptr->board[row][9];
		bFull = TRUE;
		count=0;
		while(cur_ptr < stop_ptr)
		{
			if(*cur_ptr == obcolor)
			{
				piece[count][0]  = cur_ptr - &board_ptr->board[row][0];
				while(*cur_ptr == obcolor)
					cur_ptr ++;
				piece[count++][1] = cur_ptr - &board_ptr->board[row][0];
			}
			if(!*cur_ptr)
				bFull = FALSE; 
			cur_ptr++;
		}
		while(count--)
		{
			UINT8 nums = (piece[count][1]-piece[count][0]);
			if(bFull || piece[count][0]==1 || piece[count][1] == 9)
				score += nums;
			if(piece[count][0]==1 || piece[count][1] == 9)
				score += tmpscore;
			else if(!bFull && (piece[count][0] == 2 || piece[count][1] == 8) && (row == 1 || row == 8))
				score -= tmpscore;
		}
	}
	
	return score;
}

/*找出所有在垂直方向受保护的obcolor方的棋子，并累计分数*/
INT16 scan_vertical_aixes(board_type *board_ptr, UINT8 obcolor)
{
	INT16 score=0;
	UINT8 *cur_ptr, *stop_ptr;
	UINT8  piece[4][2];
	UINT8 count=0, tmpscore;
	UINT8 bFull;
	for(UINT8 col=1; col<9; col++)
	{
        tmpscore = (col == 1 || col == 8) ? 10:2;
		cur_ptr = &board_ptr->board[1][col];
		stop_ptr= &board_ptr->board[9][col];
		bFull = TRUE;
		count=0;
		while(cur_ptr < stop_ptr)
		{
			if(*cur_ptr == obcolor)
			{
				piece[count][0]  = (cur_ptr - &board_ptr->board[0][col])/10;
				while(*cur_ptr == obcolor)
					cur_ptr += 10;
				piece[count++][1] = (cur_ptr - &board_ptr->board[0][col])/10;
			}
			if(!*cur_ptr)
				bFull = FALSE;
			cur_ptr += 10;
		}
		while(count--)
		{
			UINT8 nums = (piece[count][1]-piece[count][0]);
			if(bFull || piece[count][0]==1 || piece[count][1] == 9)
				score += nums;
			if(piece[count][0]==1 || piece[count][1] == 9)
				score += tmpscore;
			else if(!bFull && (piece[count][0] == 2 || piece[count][1] == 8) && (col == 1 || col == 8))
				score -= (tmpscore<<1);
		}
	}
   	return score;
}

/*找出所有在右上到左下方向受保护的obcolor方的棋子，并累计分数*/
INT16 scan_fd_aixes(board_type *board_ptr, UINT8 obcolor)
{
	INT16 score =0;
    UINT8 *cur_ptr, *stop_ptr, *base_ptr;
	UINT8  piece[4][2];
	UINT8 count=0, tmpscore;
	UINT8 bFull;
	for(INT8 aixes = -5; aixes <= 5; aixes++)
	{
        tmpscore = (aixes == 0) ? 10:2;
		if(aixes <=0)
		{
			base_ptr = cur_ptr = &board_ptr->board[1][8+aixes];
			stop_ptr = &board_ptr->board[9+aixes][0];
		}
		else
		{
			base_ptr = cur_ptr = &board_ptr->board[aixes+1][8];
			stop_ptr= &board_ptr->board[9][aixes];
		}
		bFull = TRUE;
		count=0;
		while(cur_ptr < stop_ptr)
		{
			if(*cur_ptr == obcolor)
			{
				piece[count][0]  = cur_ptr - board_ptr->board[0];
				while(*cur_ptr == obcolor)
					cur_ptr += 9;
				piece[count++][1] = cur_ptr- board_ptr->board[0];
			}
			if(!*cur_ptr)
				bFull = FALSE;
			cur_ptr += 9;
		}
		while(count--)
		{
			UINT8 nums = (piece[count][1]-piece[count][0])/9;
			BOOL  toborder = (piece[count][0] == base_ptr - board_ptr->board[0] || 
				piece[count][1] == stop_ptr - board_ptr->board[0]);
			if(bFull || toborder)
				score += nums;
			
			if((aixes == 1 || aixes == -1) && toborder)
				score -= tmpscore;
			/*如果是这块棋到达边界*/
			else if(toborder)
				score += tmpscore;
			/*如果有棋在角边上，则扣分*/
			else if(!bFull && (piece[count][0] == 27 ||
				piece[count][1] == 81))
				score -= (tmpscore<<1);
		}
	}
	
	/*如果角边有棋子，扣分*/
	if(board_ptr->board[1][1] == obcolor)
		score += 10;
	else 
	{
		if(board_ptr->board[1][2] == obcolor)
			score -=2;
		if(board_ptr->board[2][1] == obcolor)
			score -=2;
		if(board_ptr->board[2][2]== obcolor)
			score -=2;
	}
	
	if(board_ptr->board[8][8] == obcolor)
		score +=10;
	else
	{
		if(board_ptr->board[7][8]  == obcolor)
			score -=2;
		if(board_ptr->board[8][7]== obcolor)
			score -=2;
		if(board_ptr->board[7][7]== obcolor)
			score -= 2;
	}    
    return score;
}
/*找出所有在左上到右下方向受保护的obcolor方的棋子，并累计分数*/
INT16 scan_bd_aixes(board_type *board_ptr,  UINT8 obcolor)
{
	
    INT16 score =0;
    UINT8 *cur_ptr, *stop_ptr, *base_ptr;
	UINT8  piece[4][2];
	UINT8 count=0, tmpscore;
	UINT8 bFull;
	for(INT8 aixes = -5; aixes <= 5; aixes++)
	{
        tmpscore = (aixes == 0) ? 10:2;
		if(aixes <=0)
		{
			base_ptr = cur_ptr = &board_ptr->board[1-aixes][1];
			stop_ptr = &board_ptr->board[9][9+aixes];
		}
		else
		{
			base_ptr = cur_ptr = &board_ptr->board[1][aixes+1];
			stop_ptr= &board_ptr->board[9-aixes][9];
		}
		bFull = TRUE;
		count=0;
		while(cur_ptr < stop_ptr)
		{
			if(*cur_ptr == obcolor)
			{
				piece[count][0]  = cur_ptr - board_ptr->board[0];
				while(*cur_ptr == obcolor)
					cur_ptr += 11;
				piece[count++][1] = cur_ptr- board_ptr->board[0];
			}
			if(!*cur_ptr)
				bFull = FALSE;
			cur_ptr += 11;
		} 
		while(count--)
		{
			UINT8 nums = (piece[count][1]-piece[count][0])/11;
			BOOL  toborder = (piece[count][0] == base_ptr - board_ptr->board[0] || 
				piece[count][1] == stop_ptr - board_ptr->board[0]);
			if(bFull || toborder)
				score += nums;
			/*如果角边有棋子，扣分*/
			if((aixes == 1 || aixes == -1) && toborder)
				score -= tmpscore;
			/*如果是这块棋到达边界*/
			else if(toborder)
				score += tmpscore;
			/*如果有棋在角边上，则扣分, 主对角线方向*/
			else if(!bFull && (piece[count][0] == 22 ||
				piece[count][1] == 88))
				score -= (tmpscore<<1);
		}
	}
	
	/*如果角边有棋子，扣分*/
	if(board_ptr->board[1][8] == obcolor)
		score += 10;
	else 
	{
		if(board_ptr->board[1][7] == obcolor)
			score -=2;
		if(board_ptr->board[2][8] == obcolor)
			score -=2;
		if(board_ptr->board[2][7]== obcolor)
			score -=2;
	}
	
	if(board_ptr->board[8][1] == obcolor)
		score +=10;
	else
	{
		if(board_ptr->board[7][1]  == obcolor)
			score -=2;
		if(board_ptr->board[8][2]== obcolor)
			score -=2;
		if(board_ptr->board[7][2]== obcolor)
			score -= 2;
	} 
    return score;
}

INT16 sample_calc_board_status(board_type *board_ptr, UINT8 obcolor)
{
	INT16 score=0;
	UINT8 *ptr = &board_ptr->board[1][1];
	UINT8 *stop = &board_ptr->board[8][9]; 
	UINT8 tmpcol = ~obcolor &0x03;
	while(ptr<stop)
	{
		if(*ptr == obcolor)
			score++;
		else if(*ptr == tmpcol)
			score--;
		ptr++;
	}
	return score;
}

/*计算棋局board_ptr的状态分*/
INT16 calc_board_status(board_type *board_ptr, UINT8 obcolor)
{
    INT16 score=0;
    score += scan_horiz_aixes(board_ptr,  obcolor);
    score += scan_vertical_aixes(board_ptr, obcolor);
	score += scan_bd_aixes(board_ptr, obcolor);
	score += scan_fd_aixes(board_ptr, obcolor);
	UINT8 tmpcol = ~obcolor & 0x03 ;
	if(board_ptr->board[1][1] == tmpcol)
		score -= 44;
	if(board_ptr->board[8][8] == tmpcol)
		score -= 44;
	if(board_ptr->board[1][8] == tmpcol)
        score -= 44;
	if(board_ptr->board[8][1] == tmpcol)
		score -= 44;
	return score;
}

/*从start_pos出发找到一个可下子的点，返回受影响的子的个数，
affected_list存放受影响的棋格的指针,第一个指针为落子的点*/
const INT16 delta_array[8] = {-11, 11, -9, 9, -1, 1, -10, 10};
INT16 find_move(board_type *board_ptr, INT16 start_pos, 
				UINT8 obcolor, INT16 *affected_list)
{
	UINT8 *cel_ptr = board_ptr->board[0] + start_pos;
	UINT8 *stop_ptr = &board_ptr->board[8][9], *p;
	INT16 *aff_ptr = affected_list+1, *hold_aff;
	UINT8 aixes;
	UINT8 thithercolor = THITHER_COLOR(obcolor);
	while(1)
	{
		/*找到一个空格子*/
		while(*cel_ptr) 
			if(++cel_ptr>=stop_ptr)
				return 0;
			/*检查在8个方向上是否能吃掉对方的棋子，并记录被吃掉棋子的下标*/
			for(aixes =0;aixes<8; aixes++)
			{
				hold_aff = aff_ptr;
				p = cel_ptr + delta_array[aixes];
				while(*p == thithercolor)
				{
					*aff_ptr++ = p - board_ptr->board[0];
					p+= delta_array[aixes];
				}
				if(*p != obcolor)
					aff_ptr = hold_aff;
			}
			/*如果cel_ptr对应的点可以吃掉对方的子*/
			if(aff_ptr - affected_list > 1) 
			{
				*affected_list = cel_ptr - board_ptr->board[0];
				return (aff_ptr - affected_list);
			}
			cel_ptr++;
	}
}

void init_board(board_type *board_ptr)
{
	memset(board_ptr, 0, sizeof(board_type));
	/*init boarder*/
	memset(board_ptr->board[0], 0xff, 10);
	memset(board_ptr->board[9], 0xff, 10);
	for(int i=0; i<9; i++)
	{
		board_ptr->board[i][0] = board_ptr->board[i][9] =0xff;
	}
	
	/*init chess*/
	board_ptr->board[4][4] = board_ptr->board[5][5] = CHESS_WHITE;
	board_ptr->board[4][5] = board_ptr->board[5][4] = CHESS_BLACK;
	cur_step = 0;
	computer_side = CHESS_WHITE;
}   

/*从棋盘的一个状态出发，扩展此结点，并返回此结点的部分回溯值*/
void extend_node_one(tree_node_type *node_ptr, tree_node_type *parent_ptr,UINT8 obcolor)
{
	tree_node_type childnode;
	INT16 affected_list[MAX_AFFECTED_PIECES];
	INT16 start_pos = 11, num;
	num = find_move(&node_ptr->board, start_pos, obcolor, affected_list);
	/*如果是终局状态，则返回状态估值函数的值*/
	if(++cur_depth == max_depth || num==0 )
	{
		/*如果已方PASS但没到棋局结束,要扣分*/
		node_ptr->value = calc_board_status(&node_ptr->board, computer_side);
		if(!num)
		{
			/*如果双方都没棋下*/
			if(!find_move(&node_ptr->board, 11, ~obcolor&0x03, affected_list)) 
				return;
			
			if(obcolor == computer_side)
			{
				node_ptr->value -= 15;
				return ;
			}
			node_ptr->value += 15;
		}
		return;		   
	}
	/*初始化回溯值*/ 
	node_ptr->value = (obcolor == computer_side)? -INITIAL_VALUE : INITIAL_VALUE;
	memcpy(&childnode.board, &node_ptr->board, sizeof(board_type));
	while(num)
	{
		while(num--)
			childnode.board.board[0][affected_list[num]] = obcolor;
		/*递归计算部分回溯值*/
		UINT8 depth = cur_depth;
		extend_node_one(&childnode, node_ptr, (~obcolor)&0x03);
		cur_depth = depth;
		/*如果此结点是棋手一方，则部分回溯值是子结点中最大的一个*/
		if(obcolor == computer_side)
		{
			if(childnode.value > node_ptr->value)
			{
				node_ptr->value = childnode.value; 
				node_ptr->movepos = affected_list[0];
			}
		}
		/*如果是对手一方，部分回溯值是子结点中最小的一个*/ 
		else
		{
			if(childnode.value < node_ptr->value)
			{
				node_ptr->value = childnode.value;
				node_ptr->movepos = affected_list[0];
			}
		}
		/* α-β裁减的判断   在考虑轮到棋手下棋的一个亲节点及轮到对手下棋的一个子节点时，
		如果该子节点的数值已经小于或等于其亲节点的回溯值，
		那么就不需要对该节点或者其后续节点做更多的处理了。
		计算的过程可以直接返回到亲节点上。
		*/
		/*在考虑轮到对手下棋的一个亲节点及轮到棋手下棋的一个子节点时，
		如果该子节点的部分回溯值已经大于或等于其亲节点的部分回溯值，
		那么就不需要对该子节点或者其后裔节点做更多的处理了。
		计算过程可以直接返回到亲节点上。*/
		if(parent_ptr)
		{
			if(obcolor != computer_side)
			{
				/*α裁减*/
				if(node_ptr->value <= parent_ptr->value)
					return;
			}
			else
			{
				/*β裁减*/
				if(node_ptr->value >= parent_ptr->value)
					return;
			}
		}
		/*找到下一个可落子的点*/
		start_pos = affected_list[0]+1;
		memcpy(&childnode.board, &node_ptr->board, sizeof(board_type));
		num = find_move(&childnode.board, start_pos, obcolor, affected_list);
	}
	return;
}


void extend_node_two(tree_node_type *node_ptr, tree_node_type *parent_ptr,UINT8 obcolor)
{
	tree_node_type childnode;
	INT16 affected_list[MAX_AFFECTED_PIECES];
	INT16 start_pos = 11, num;
	num = find_move(&node_ptr->board, start_pos, obcolor, affected_list);
	/*如果是终局状态，则返回状态估值函数的值*/
	if(!num)
	{
		/*如果已方PASS但没到棋局结束,要扣分*/
		node_ptr->value = sample_calc_board_status(&node_ptr->board, computer_side);
		/*如果双方都没棋下*/
		if(!find_move(&node_ptr->board, 11, ~obcolor&0x03, affected_list)) 
			return;
		
        if(obcolor == computer_side)
		{
			node_ptr->value -= 10;
			return;
		}
		node_ptr->value += 10;
		return;
	}
	/*初始化回溯值*/ 
	node_ptr->value = (obcolor == computer_side)? -INITIAL_VALUE : INITIAL_VALUE;
	memcpy(&childnode.board, &node_ptr->board, sizeof(board_type));
	while(num)
	{
		while(num--)
			childnode.board.board[0][affected_list[num]] = obcolor;
		/*递归计算部分回溯值*/
		UINT8 depth = cur_depth;
		extend_node_two(&childnode, node_ptr, (~obcolor)&0x03);
		cur_depth = depth;
		/*如果此结点是棋手一方，则部分回溯值是子结点中最大的一个*/
		if(obcolor == computer_side)
		{
			if(childnode.value > node_ptr->value)
			{
				node_ptr->value = childnode.value; 
				node_ptr->movepos = affected_list[0];
			}
		}
		/*如果是对手一方，部分回溯值是子结点中最小的一个*/ 
		else
		{
			if(childnode.value < node_ptr->value)
			{
				node_ptr->value = childnode.value;
				node_ptr->movepos = affected_list[0];
			}
		}
		/* α-β裁减的判断   在考虑轮到棋手下棋的一个亲节点及轮到对手下棋的一个子节点时，
		如果该子节点的数值已经小于或等于其亲节点的回溯值，
		那么就不需要对该节点或者其后续节点做更多的处理了。
		计算的过程可以直接返回到亲节点上。
		*/
		/*在考虑轮到对手下棋的一个亲节点及轮到棋手下棋的一个子节点时，
		如果该子节点的部分回溯值已经大于或等于其亲节点的部分回溯值，
		那么就不需要对该子节点或者其后裔节点做更多的处理了。
		计算过程可以直接返回到亲节点上。*/
		if(parent_ptr)
		{
			if(obcolor != computer_side)
			{
				/*α裁减*/
				if(node_ptr->value <= parent_ptr->value)
					return;
			}
			else
			{
				/*β裁减*/
				if(node_ptr->value >= parent_ptr->value)
					return ;
			}
		}
		/*找到下一个可落子的点*/
		start_pos = affected_list[0]+1;
		memcpy(&childnode.board, &node_ptr->board, sizeof(board_type));
		num = find_move(&childnode.board, start_pos, obcolor, affected_list);
	}
	return;
}

void get_chess_score(board_type *board_ptr, UINT16 &iWscore, UINT16 &iBscore)
{
	iWscore =0; iBscore =0;
	for(INT16 i=1; i<=BOARD_ROWS; i++)
		for(INT16 j=1; j<=BOARD_COLS; j++)
		{
			if(board_ptr->board[i][j]  == CHESS_BLACK)
				iBscore++;
			else  if(board_ptr->board[i][j] == CHESS_WHITE)
				iWscore++;
		}
}

void game_over(board_type *board_ptr, HWND hwnd)
{
	UINT16 wscore, bscore;
	char strcomwin[]="虽然你很历害,但我还是赢了你!";
	char struserwin[]="让你一次,下次你可没这么走运了!";
	char strdogfall[]="我没好好下,你才有机会平局!";
	char *text;
	get_chess_score(board_ptr, wscore, bscore);

	g_bStart = 0;
	
	if(computer_side == CHESS_WHITE)
	{
		if(wscore > bscore)
		{
			text = strcomwin;
		}
		else if(wscore <bscore)
		{
			text = struserwin;
		}
		else
		{
			text = strdogfall;
		}
	}
	else
	{
		if(wscore > bscore)
			text = struserwin;			
		else if(wscore <bscore)
			text = strcomwin;
		else text = strdogfall;
	}
	MessageBox(hwnd,  text, "黑白棋", MB_OK|MB_ICONINFORMATION);
}

void computer_play(board_type *board_ptr, HWND hwnd)
{
	cur_depth =0;
	tree_node_type node;
	INT16 affected_list[MAX_AFFECTED_PIECES];
start:
	memcpy(&node.board, board_ptr, sizeof(board_type));
	node.movepos =0;
	if(cur_step>= STEP_MONMENT2)
	{
		extend_node_two(&node, NULL, computer_side);
	}
	else if(cur_step > STEP_MONMENT1)
	{
		max_depth = depth2[g_iGameLevel];
		extend_node_one(&node, NULL, computer_side);
	}
	else 
	{
		max_depth = depth1[g_iGameLevel];
		extend_node_one(&node, NULL, computer_side);
	}
	
	if(!do_move_chess(board_ptr, node.movepos, computer_side, hwnd))
	{
		if(!find_move(board_ptr, 11, (~computer_side)&0x03, affected_list))
		{
			game_over(board_ptr, hwnd);
			return;
		}
		else
		{
			MessageBox(hwnd,"我没棋下了,你再走一步!", "黑白棋", MB_OK|MB_ICONINFORMATION);
			return;
		}
	}
	else
	{ 
		if(!find_move(board_ptr, 11, (~computer_side)&0x03, affected_list))
		{
			if(!find_move(board_ptr, 11, computer_side, affected_list))
			{
				game_over(board_ptr, hwnd); 
				return;
			}
			else
			{
				
				MessageBox(hwnd ,"你没棋下了,我再走一步!", "黑白棋", MB_OK|MB_ICONINFORMATION);
				
				goto start;
			}
			
		}
	}
} 

UINT8 do_move_chess(board_type *board_ptr, UINT16 movepos, UINT8 obcolor, HWND hwnd)
{
	INT16 affected_list[MAX_AFFECTED_PIECES];
	INT16 num = find_move(board_ptr, movepos, obcolor, affected_list);
	if(!num || affected_list[0] != movepos)
		return 0; 
	for(int i=0; i<num; i++)
	{
		board_ptr->board[0][affected_list[i]] = obcolor;
		if(hwnd)
			::SendMessage(hwnd, WM_TRANCHESS, WPARAM(affected_list[i]),LPARAM(i<<16|obcolor));
	}
	step_array[cur_step++] = movepos;
	
	return 1;
}