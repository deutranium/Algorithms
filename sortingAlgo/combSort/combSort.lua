local function combSort(t)
    local n = #t
    local gap = n
    local shrink = 1.3
    local swapped = true
    while gap > 1 or swapped do
        gap = math.floor(gap / shrink)
        if gap < 1 then
            gap = 1
        end
        swapped = false
        for i = 1, n - gap do
            if t[i] > t[i + gap] then
                t[i], t[i + gap] = t[i + gap], t[i]
                swapped = true
            end
        end
    end
end

local t = { 3, 2, 1, 4, 5, 6, 7, 8, 9, 10 }
combSort(t)
print(table.concat(t, ", "))